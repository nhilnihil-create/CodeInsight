#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const long double pi = 3.141592653589793;



int main(){
    string S;
  	cin>>S;
  	ll K;
  	cin>>K;
  	K--;
  	ll Sz=S.size();
  	ll F;
  	ll FF;
    rep(i, Sz){
      if(S.at(i)!='1'){
        	F=i;
        	FF=S.at(i)-'0';
        	break;
      }
    }	
  	if(K>=F){
		cout<<FF<<endl;
    }else{
  		cout<<1<<endl;
    } 
}