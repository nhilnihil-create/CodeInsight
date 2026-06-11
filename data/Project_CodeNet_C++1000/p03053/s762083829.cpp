#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<int,int>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    char s[h][w];
    queue<pair<P,int>> que;
    rep(i,h){
        rep(j,w){
            cin>>s[i][j];
            if(s[i][j]=='#')que.push(make_pair(make_pair(i,j),0));
        }
    }
    int ans=0;
    while(!que.empty()){
        pair<P,int> p=que.front();
        que.pop();
        chmax(ans,p.sc);
        int i=p.ft.ft;
        int j=p.ft.sc;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                if(abs(x+y)==1&&0<=i+x&&i+x<h&&0<=j+y&&j+y<w){
                    if(s[i+x][j+y]=='.'){
                        que.push(make_pair(make_pair(i+x,y+j),p.sc+1));
                        s[i+x][j+y]='#';
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
//どうしてもわからないときはサンプルで実験　何か見えてくるかも
//頭で考えてダメなら紙におこせ！！
/*
V,P(大文字)使用不可
乗算などの際にオーバーフローに注意せよ！
(適切にmodをとれ　にぶたんで途中で切り上げろ)
制約をよく読め！
{
    ・全探索できるなら全探索しろ
    ・異常な制約ならそこに注目
}
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'¥n'
グリッド上では行先が範囲内におさまるかif文で確認(RE注意)
if文ではちゃんと比較演算子==を使え('='でもエラー出ない)
配列(vector)の大きさが0か1以上かで場合分けせよ(RE注意)
(vector<int> a(m)でm==0というものはできない)
modはなるべく最後に取れ！
doubleを扱うときには(abs)ではなく'fabs'!!!
*/