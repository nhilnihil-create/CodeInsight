#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const int Nmax=2e5+1;
const int Nd=61;
const int INF=1e5;


int main(){
  int n,a,b,c,d;
  string s;
  cin>>n>>a>>b>>c>>d>>s;
  int ns=s.size();

  int st=min(a,b);
  int goal=max(c,d);
  bool okTen3=false;
  bool okIwa2=true;
  int r_iwa=0;
  int r_ten=0;

  for (int i=st; i<=goal; i++){
    if(s[i-1]=='.'){
      r_ten++;
      r_iwa=0;
      if(r_ten>=3 && i>=b+1 && i<=d+1){
        okTen3=true;
      }
    }else{
      r_iwa++;
      r_ten=0;

      if(r_iwa>=2){
        okIwa2=false;
        cout<<"No"<<endl;
        return 0;
      }

    }
  }
  if(c<d){
    cout<<"Yes"<<endl;
    return 0;
  }

  if(c>d && okTen3){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;


}
