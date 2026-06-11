#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
typedef priority_queue<string> priquest;
typedef priority_queue<string,vector<string>,greater<string>> rpriquest;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

const ll big=1000000007;
int exp(int x,int y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x)%big;
    int t=exp(x,y/2);
    return (t*t)%big;
}
void chmin(ll a,ll b){
    if(a>b)a=b;
    return;
}

typedef pair<ll,int> pii;
typedef priority_queue<pii,vector<pii>,greater<pii>> prpi;

int main(){
    int n,c;cin >> n >> c;
    vector<vector<int>> d(c,vector<int>(c)),col(n,vector<int>(n));
    rep(i,c)rep(j,c){
        cin >> d[i][j];
    }rep(i,n)rep(j,n){
        cin >> col[i][j];
    }
    //全探索するとcP3 * n^2=O(c^3*n^2)でぎり間に合う…？無理か
    //前処理的に、(i+j%3==0)の点に対して3番目までに最適な色変化を保持しておく
    //あとで組み合わせればok
    //大体n*n*c*3くらいの計算
    vector<prpi> ans(3);//<min,color>を保持する
    rep(aa,3){
        rep(co,c){
        ll cnt=0;//aaをcoに変えた時の違和感の総和
        rep(i,n)rep(j,n){
            if((i+j)%3!=aa)continue;
            cnt+=d[col[i][j]-1][co];
        }
        ans[aa].push(pii(cnt,co));
        }
    }
    
    ll val=-1;
    vector<vector<pii>> last(3,vector<pii>(3));
    rep(i,3){
        rep(j,3){
            last[i][j]=ans[i].top();
            ans[i].pop();
        }
    }
    
    rep(i,3)rep(j,3){
        if(last[0][i].second==last[1][j].second)continue;
        
        rep(k,3){
            if(last[0][i].second==last[2][k].second||last[2][k].second==last[1][j].second)continue;
            if(val==-1)val=last[0][i].first+last[1][j].first+last[2][k].first;
            else val=min(last[0][i].first+last[1][j].first+last[2][k].first,val);
        }
    }
    cout << val << '\n';
}