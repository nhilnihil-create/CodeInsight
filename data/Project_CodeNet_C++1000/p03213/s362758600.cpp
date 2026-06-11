#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


vector<ll> Eratosthenes( const ll N )
{
    std::vector<bool> is_prime( N + 1 );
    for( ll i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    std::vector<ll> P;
    for( ll i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( ll j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}


int main(){
    vl A=Eratosthenes(101);
    ll N;
    cin >> N;
    Map count;
    for(auto p: A){
        ll s=N;
        ll ret=0;
        while(s>0){
           s/=p;
           ret+=s; 
        }
        count[p]=ret;
    }
    Map R;
    for(auto p: count){
        R[p.second]++;
    }
    ll N75=0,N25=0,N15=0,N5=0,N3=0;
    for(ll i=100;i>=74;i--)N75+=R[i];
    N25+=N75;
    for(ll i=73;i>=24;i--)N25+=R[i];
    N15+=N25;
    for(ll i=23;i>=14;i--)N15+=R[i];
    N5+=N15;
    for(ll i=13;i>=4;i--)N5+=R[i];
    N3+=N5;
    for(ll i=3;i>=2;i--)N3+=R[i];
    ll ans=0;
    //3,5,5
    if(N5>=2&&N3>=3)ans+=(N5*(N5-1)/2)*(N3-2);
    //3,25
    if(N25>=1&&N3>=2)ans+=N25*(N3-1);
    //5,15
    if(N15>=1&&N5>=2)ans+=N15*(N5-1);
    //75
    if(N75)ans+=N75;

    print(ans)

    return 0;
}