#include <bits/stdc++.h>
using namespace std;

typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;
typedef vector< vector< vector<ll> > > vvvint;
typedef vector<string> vstring;
typedef vector< vector<string> > vvstring;
typedef vector<char> vchar;
typedef vector< vector<char> > vvchar;
typedef vector<long double> vdouble;
typedef vector< vector<long double> > vvdouble;
typedef vector< vector< vector<long double> > > vvvdouble;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;
typedef vector<bool> vbool;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ALL(obj) (obj).begin(), (obj).end()
// #define LLONG_MAX 9223372036854775806
#define MOD 1000000007
const double PI=3.14159265358979323846;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> T Ceil(T a, T b){return (a+b-1)/b;}

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};

void printv(vint &v){
    for(auto e:v) cout<<e<<" ";
        cout<<endl;
    }

int main() {
    cout<<fixed<<setprecision(10);
    ll m,k; cin>>m>>k;

    if(k==0){
        rep(i,(1ll<<m)){
            cout<<i<<" "<<i<<" ";
        }
        cout<<endl;
        return 0;
    }

    ll s = 0;
    rep(i,(1ll<<m)){
        if(i==k) continue;
        s = s^i;
    }

    if(s == k){
        vint ans;
        rep(i,(1ll<<m)){
            if(i==k) continue;
            ans.push_back(i);
        }
        ans.push_back(k);
        repr(i,(1ll<<m)){
            if(i==k) continue;
            ans.push_back(i);
        }
        ans.push_back(k);

        printv(ans);

    }else{
        cout<<-1<<endl;
    }


    return 0;

}