#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define LIMIT 1000000007 //10^9+7
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()

template<class H>
void CIN(H& h){cin>>h;}
template<class H, class... T>
void CIN(H &h, T&... t){cin>>h;CIN(t...);}

int main(){
	vi z(5);
  rep(i,5)cin>>z[i];
  int k;cin>>k;

  bool ok = false;
  for(int i=0; i<5; i++){
    for(int j=i+1; j<5; j++){
      if(z[j]-z[i]>k)ok=true;
    }
  }


  cout<<(ok?":(":"Yay!")<<endl;
}