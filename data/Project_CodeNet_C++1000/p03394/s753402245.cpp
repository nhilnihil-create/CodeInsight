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
ll const Cons = 30000;
vint ans;
void solve(ll N){

    ll c1,c2;
    c1 = -1; c2 = -1;

    for(ll m1=1; 2*(3*m1-1)<=Cons; m1++){
        c1 = 3*m1 -1;
        c2 = N - c1;
        if(c2%2==0 && (c1*c2 != 0) && (3*(2*c2-1)) <= Cons){break;}
        else c2 = -1;
    }

    if(c2 == -1){
        for(ll m1=1; 2*3*m1<=Cons; m1++){
            c1 = 3*m1;
            c2 = N - c1;
            if(c2%2==0 && (c1*c2 != 0) && (3*(2*c2-1)) <= Cons){break;}
            else c2 = -1;
        }
    }

    // cout<<c1<<" "<<c2<<endl;
    // if(c1*c2 < 0) cout<<N<<endl;
    // assert(c1*c2 != 0);
    // assert(c2 > 0);
    rep(i,c1) cout<<2*(i+1)<<" ";
    rep(i,c2) cout<<3*(2*i+1)<<" ";
    puts("");
}

int main() {
    cout<<fixed<<setprecision(10);

    ll N; cin>>N;

    if(N==3){
        cout<<"2 5 63"<<endl;
    }else if(N==5){
        cout<<"2 3 4 5 16"<<endl;
    }else{
        solve(N);
    }

    // repf(i,3,N) solve(i);

    // puts("");
    // ll tot = 0;
    // for(auto e:ans)tot+=e;
    // for(auto e:ans){
    //     if(gcd(e, tot-e) == 1){
    //         puts("hage");
    //     }
    // }




    return 0;

}