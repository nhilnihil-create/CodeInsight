#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  string s;cin>>s;
  ll q;cin>>q;
  ll d = 0,m = 0,dm = 0;
  while(q--){
    ll k;cin>>k;
    ll ans = 0;
    d = 0;m = 0;dm = 0;
    for(int i=0;i<n;i++){
      if(i >= k-1){
	if(s[i] == 'D'){
	  d++;
	}else if(s[i] == 'M'){
	  dm += d;
	  m++;
	}else if(s[i] == 'C'){
	  ans += dm; 
	}

	if(s[i-k+1] == 'D'){
	  d--;
	  dm -= m;
	}else if(s[i-k+1] == 'M'){
	  m--;
	}

      }else{
	if(s[i] == 'D'){
	  d++;
	}else if(s[i] == 'M'){
	  dm += d;
	  m++;
	}else if(s[i] == 'C'){
	  ans += dm; 
	}
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
