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
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
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

ll ans = INF;
int main() {
    ll N,A,B,C;
    cin >>N>>A>>B>>C;
    vector<ll>l(N);

    rep(i,N)cin>>l[i];

    rep(i,(1<<(N*2))){
        vector<ll> S(N);
        ll tmp = i;
        rep(j,N){
            S[j]=tmp%4;
            tmp /= 4;
        }
        ll a=0,b=0,c=0;
        ll now = -30;
        rep(j,N){
            if(S[j] == 0){
                a+=l[j];
                now +=10;
            }else if(S[j] == 1){
                b+=l[j];
                now +=10;
            }else if(S[j] == 2){
                c+=l[j];
                now +=10;
            }
        }
    //cout<<a<<" "<<b<<" "<<c<<endl;
        if(a==0 || b==0 || c== 0)continue;
        now += abs(A-a)+abs(B-b)+abs(C-c);
        chmin(ans,now);
        
        
    }
    cout << ans << endl;


    return 0;
    

}