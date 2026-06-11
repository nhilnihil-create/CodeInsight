#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.second != b.second){
        return a.second > b.second;
        
    }else{
        return a.first < b.first;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N,H;
    cin >>N>>H;
    vector<Pi>ab(N);
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        ab[i]=mp(a,b);
    }

    sort(all(ab));
    ll ma=ab[N-1].first;
    ll mb=ab[N-1].second;
    ab[N-1].second=-1;
    sort(all(ab),compare);
    ll ans=0;
    rep(i,N){
        if(H<=mb){
            ans++;
            cout<<ans<<endl;
            return 0;
        }else if(ab[i].second>ma){
            H-=ab[i].second;
            ans++;
            if(H<=0){
                cout<<ans<<endl;
                return 0;
            }
        }else{
            break;
        }
    }
    ans++;
    H-=mb;
    if(H<=0){
        cout<<ans<<endl;
        return 0;
    }
    ans+=(H-1)/ma + 1;

    cout << ans << endl;


    return 0;
    

}