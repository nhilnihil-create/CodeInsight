#include<bits/stdc++.h>
using ll  = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define erep(e,v) for(auto && e :v)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
using namespace std;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
template<class T> void join(T &a){int t = 0;for(auto itr :a){if(t++)cout << " "; cout << itr;} cout <<endl; }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}

template <class T>
class Cumulative2DSum {
    // query[sx,gx),[sy,gy)
public:
    vector<vector<T>>sum;
    T e;
    Cumulative2DSum(vector<vector<T>>&v,T e) {
        // W is x, H is y
        int W = v.front().size();
        int H = v.size();
        ++H , ++W;
        sum = vector<vector<T>>(H,vector<T>(W,e));
        
        for(int i = 0; i < v.size(); ++i){
            for(int j = 0; j < v[i].size(); ++j){
                sum[i + 1][j + 1] +=  v[i][j];
            }
        }
        for(int i = 1; i < sum.size(); ++i){
            for(int j = 1; j < sum[i].size();++j){
                sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
    }
    T query(int sx,int sy,int gx,int gy){
        return sum[gy][gx] - sum[sy][gx] - sum[gy][sx] + sum[sy][sx];
    }
};


signed main(){
    int n,m,Q;
    cin >> n >> m >> Q;
    vector<vector<int>>grid(n,vector<int>(n,0LL));
    rep(_,m){
        int l,r; cin >> l >> r;
        --l,--r;
        grid[l][r]++;
    }
    auto dcm = Cumulative2DSum<int>((grid),0LL);
    rep(_,Q){
        int l,r; cin >> l >> r;
        --l,--r;
        cout << dcm.query(l,l,r+1,r+1) <<endl;
    }
}

