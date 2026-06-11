#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
using namespace std;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

template<typename ...Ts>
void show(Ts... ts){
  cout<<"#:";
  auto print=[](auto v){cout<<v<<" ";};
  initializer_list<int>{(void(print(ts)),0)...};
  cout<<endl;
}



int main(void){
    ll a;
    ll ans=0;
    string s;
    cin>>s;
    int n=s.size();
    vll N(n+1,0);
    vll A(n+1,0);
    vll AB(n+1,0);
    vll ABC(n+1,0);
    N[0]=1;

    REP(i,1,n+1){
        N[i]=N[i-1];
        A[i]=A[i-1];
        AB[i]=AB[i-1];
        ABC[i]=ABC[i-1];
        switch(s[i-1]){
            case '?':
                N[i]+=2*N[i-1];
                A[i]+=2*A[i-1]+N[i-1];
                AB[i]+=2*AB[i-1]+A[i-1];
                ABC[i]+=2*ABC[i-1]+AB[i-1];
                break;

            case 'A':
                A[i]+=N[i-1];
                break;            

            case 'B':
                AB[i]+=A[i-1];
                break;          
                
            case 'C':
                ABC[i]+=AB[i-1];
                break;            
        }
        N[i]%=mod;
        A[i]%=mod;
        AB[i]%=mod;
        ABC[i]%=mod;
    }
    ans=ABC[n];
    cout<<ans<<endl;
    //solve(t);
}
