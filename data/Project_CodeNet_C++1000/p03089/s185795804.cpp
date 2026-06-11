#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 1000000;
const int INF = 1e9;
const double pi=acos(-1);


int main(){
  int n;
  cin >> n;
  vector<int>b;
  rep(i,n){
    int B;
    cin >> B;
    b.push_back(B);
    if(b[i]>i+1){
      cout << -1 << endl;
      return 0;
    }
  }
  int num=n;
  vector<int>ans;
  while(num){
    int kesu=-1;
    rep(i,num){
      if(b[i]==i+1){
        if(kesu<i)kesu=i;
      }
    }
    if(kesu==-1){
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(b[kesu]);
    b.erase(b.begin()+kesu);
    num--;
  }
  rep(i,n) cout<<ans[n-1-i]<<endl;
  return 0;
}
