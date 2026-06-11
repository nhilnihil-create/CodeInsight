#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];


  int res = 0;
  for(int i = 29; i >= 0 ; i--){
    long long summ = 0;
    int mini = 1 << i;
    int maxi = 1 << (i+1);
    for(int mod = 0 ; mod < n ; mod++) a[mod] %= maxi, b[mod] %= maxi;
    sort(b.begin(),b.end()); //ソートしておく事で領域で分けられる
    for(int j = 0 ; j < n; j++){
      int add = 0;
      if(mini-a[j] >= 0) add += lower_bound(b.begin(), b.end(), maxi-a[j]) - lower_bound(b.begin(), b.end(), mini-a[j]);
      else {
        add += lower_bound(b.begin(), b.end(), maxi-a[j]) - b.begin();
        add += lower_bound(b.begin(), b.end(), maxi) - lower_bound(b.begin(), b.end(), maxi+mini-a[j]);
      }
      summ += add;
    }
    if(summ & 1) res += mini;  //1とのXOR
  }
  cout << res << endl;
}
