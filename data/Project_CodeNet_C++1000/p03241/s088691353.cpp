#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define lp(i,n) for(int i=0;i<(n);i++)
#define lps(i,j,n) for(int i=j;i<n;i++)

#define fordebug int hoge;cin>>hoge;

#define DEKAI 1000000007
#define floot10 cout<<fixed<<setprecision(15)
#define all(v) v.begin(),v.end()
double PI = acos(-1);

signed main(){
  int n,m;
  cin>>n>>m;

  //mの約数を探す
  vector<int> yakusuu;
  for(int i=1;i*i<=m;i++){
    if(m%i==0){
      //割り切れるなら、iとm/iが約数
      yakusuu.push_back(i);
      yakusuu.push_back(m/i);
    }
  }
  //ソートする(小さい順になる)
  sort(yakusuu.begin(),yakusuu.end());
  
  // m/n以下の中で一番大きいのを探す。
  // x*n<=m
  int ans=1;
  for(int i=0;i<yakusuu.size();i++){
    if(yakusuu[i]*n<=m)ans=yakusuu[i];
    else break;
  }
  cout<<ans<<endl;
  return 0;
}
