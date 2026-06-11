#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
//typedef tuple<ll, ll, ll> T;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    const int size = log2(*max_element(a.begin(),a.end())+*max_element(b.begin(),b.end()));
    int ans=0;
    vector<int> bb(n);
    for(int i=0,t=1;i<=size;++i){
        for(int j=0;j<n;++j) bb[j] = b[j] % (2*t);
        sort(bb.begin(),bb.end());
        ll cnt=0;
        for(int j=0;j<n;++j){
            const int aa=a[j]%(2*t);
            cnt += distance(lower_bound(bb.begin(),bb.end(),t-aa),
                            lower_bound(bb.begin(),bb.end(),2*t-aa));
            cnt += distance(lower_bound(bb.begin(),bb.end(),3*t-aa),
                            lower_bound(bb.begin(),bb.end(),4*t-aa));
        }
        ans+=(cnt%2)*t;
        t*=2;
    }
    cout<<ans<<endl;
}
