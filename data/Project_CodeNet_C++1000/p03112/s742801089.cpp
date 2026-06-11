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


int main() {
    ll A,B,Q;
    cin >>A>>B>>Q;
    vector<ll>s(A);
    vector<ll>t(B);

    rep(i,A) cin>>s[i];
    rep(i,B) cin>>t[i];
    sort(all(s));
    sort(all(t));

    rep(i,Q){
        ll x;
        ll ans = INF;
        cin>>x;
        ll d1,d2;
        ll now = 0;
        ll inx;
        ll inx1,inx2;
        inx = lower_bound(all(s), x) - s.begin();
        if(inx == 0){
            d1 = s[inx];
            inx = lower_bound(all(t), d1) - t.begin();
            if(inx == 0){
                chmin(ans,abs(x-d1)+abs(d1-t[inx]));
            }else{
                chmin(ans,abs(x-d1)+abs(d1-t[inx]));
                chmin(ans,abs(x-d1)+abs(d1-t[inx-1]));
            }
        }else{
            d1 = s[inx];
            d2 = s[inx-1];
            inx1 = lower_bound(all(t), d1) - t.begin();
            inx2 = lower_bound(all(t), d2) - t.begin();
            if(inx1 == 0){
                chmin(ans,abs(x-d1)+abs(d1-t[inx1]));
            }else{
                chmin(ans,abs(x-d1)+abs(d1-t[inx1]));
                chmin(ans,abs(x-d1)+abs(d1-t[inx1-1]));
            }

            if(inx2 == 0){
                chmin(ans,abs(x-d2)+abs(d2-t[inx2]));
            }else{
                chmin(ans,abs(x-d2)+abs(d2-t[inx2]));
                chmin(ans,abs(x-d2)+abs(d2-t[inx2-1]));
            }
        }

        inx = lower_bound(all(t), x) - t.begin();
        if(inx == 0){
            d1 = t[inx];
            inx = lower_bound(all(s), d1) - s.begin();
            if(inx == 0){
                chmin(ans,abs(x-d1)+abs(d1-s[inx]));
            }else{
                chmin(ans,abs(x-d1)+abs(d1-s[inx]));
                chmin(ans,abs(x-d1)+abs(d1-s[inx-1]));
            }
        }else{
            d1 = t[inx];
            d2 = t[inx-1];
            inx1 = lower_bound(all(s), d1) - s.begin();
            inx2 = lower_bound(all(s), d2) - s.begin();
            if(inx1 == 0){
                chmin(ans,abs(x-d1)+abs(d1-s[inx1]));
            }else{
                chmin(ans,abs(x-d1)+abs(d1-s[inx1]));
                chmin(ans,abs(x-d1)+abs(d1-s[inx1-1]));
            }

            if(inx2 == 0){
                chmin(ans,abs(x-d2)+abs(d2-s[inx2]));
            }else{
                chmin(ans,abs(x-d2)+abs(d2-s[inx2]));
                chmin(ans,abs(x-d2)+abs(d2-s[inx2-1]));
            }
        }
        cout<< ans << endl;
    }
    


    return 0;
    

}