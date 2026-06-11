#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//const ll mod = ;
//const ld error = ;
const ld PI = acosl(-1);

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

struct print{
    print(){cerr<<"LINE "<<__LINE__<<" >> ";}
    ~print(){cerr<<endl;}
    template<class c> print& operator,(c i){
        cerr<<boolalpha<<i; return *this;}
};
#define dbg(x) " [" , #x ": " , (x) , "] "
#define tham getchar()

mt19937_64 rng((unsigned)chrono::system_clock::now().time_since_epoch().count());
//inline ll MOD(ll x, ll m = mod){
//    ll y = x % m;
//    return (y >= 0) ? y: y+m;
//}

//const int inf = ;
//const ll infl = ;
const int nmax = 1e5+5;
///===========================================  template  =======================================================

ll input[nmax];

int main(){
    FASTIO;

    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    ll l = 2, r = 2;
    for(int i = n-1; i>=0; i--){
        l = input[i] * ((l-1)/input[i] + 1);
        r = input[i] * (r/input[i]);

        if(l > r){
            cout<<-1<<endl;
            return 0;
        }

        r += input[i]-1;
    }

    cout<<l<<" "<<r<<endl;

    return 0;
}
