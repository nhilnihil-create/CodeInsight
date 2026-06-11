#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
  }
  int r=1, sum=a[0], xxor=a[0];
  ll ans=0;
  rep(i, n){
    int l=i;
    if(i!=0){
      sum-=a[i-1];
      xxor^=a[i-1];
    }
    while(r<n && sum+a[r]==(xxor^a[r])){
      sum+=a[r];
      xxor^=a[r];
      r++;
      //cout << sum << " " << xxor << " " << r << endl;
    }

    //cout << l <<  " " << r << endl;
    if(sum!=xxor)continue;
    ans+=r-l;
  }
  cout << ans << endl;
  return 0;
}
