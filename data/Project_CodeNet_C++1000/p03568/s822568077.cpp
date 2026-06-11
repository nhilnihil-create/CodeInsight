#include <iostream>
#include <vector>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
typedef long long ll;


int main(){
  int n;
  cin >> n;
  vector<int> v;
  rep(i, n){
    int a;
    cin >> a;
    if(a % 2 == 0){
      v.push_back(2);
    }else{
      v.push_back(1);
    }
  }
  ll res = 1;
  ll res2 = 1;
  rep(i, n){
    res *= 3;
    res2 *= v[i];
  }
  cout << res - res2 << endl;
}
