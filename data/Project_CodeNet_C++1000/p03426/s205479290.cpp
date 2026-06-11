#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,d;cin >> h >> w >> d;
    vector<P> v(h*w);
    rep(i,h) rep(j,w){
        int a;cin >> a;
        --a;
        v[a] = {i,j};
    }

    auto f =[&](int a,int b){
        return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
    };

    vector<vl> table(d, vl(dup(h*w,d)+1,0)); 
    for(int i=0;i<d;++i){
        for(int j=1;i+j*d<h*w;++j){
            table[i][j] = table[i][j-1] + f(i+(j-1)*d,i+j*d);
            //cerr << "i=" << i << ":j=" << j << " ";
            //call(table[i][j]);
        }
    }

    int q;cin >> q;
    while(q--){
        int x,y;cin >> x >> y;
        --x;--y;
        //cerr << "ans is ";
        printf("%lld\n", table[x%d][y/d] - table[x%d][x/d]);
        //cout << table[x%d][y] - table[x%d][x] << endl;
        //cerr << table[x%d][y/d]  << " " <<  table[x%d][x/d] << "\n";
    }
}