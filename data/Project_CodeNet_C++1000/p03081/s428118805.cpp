#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,Q;
    cin>>n>>Q;
    string s;
    cin>>s;
    s.insert(0,"x");
    s+='x';
    V<char> t(Q),d(Q);
    rep(i,Q) cin>>t[i]>>d[i];
    int rans=0;
    int left=0,right=n+1;
    while(right-left>1){
        int mid=(right+left)/2;
        bool ok=0;
        int k=mid;
        rep(i,Q){
            if(s[k]==t[i]){
                if(d[i]=='L') k--;
                else k++;
                if(k==0){
                    ok=1;
                    break;
                }
            }
        }
        if(ok) left=mid;
        else right=mid;
    }
    rans+=left;
    left=0,right=n+1;
    while(right-left>1){
        int mid=(right+left)/2;
        bool ok=0;
        int k=mid;
        rep(i,Q){
            if(s[k]==t[i]){
                if(d[i]=='L') k--;
                else k++;
                if(k==n+1){
                    ok=1;
                    break;
                }
            }
        }
        if(ok) right=mid;
        else left=mid;
    }
    rans+=n-right;
    cout<<n-rans-1<<endl;
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
/*
V,P(大文字)使用不可
乗算などの際にオーバーフローに注意せよ！
(適切にmodをとれ　にぶたんで途中で切り上げろ)
制約をよく読め！
(全探索できるなら全探索しろ)
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'\n'
グリッド上では行先が範囲内におさまるかif文で確認(RE注意)
if文ではちゃんと比較演算子==を使え(=でもエラー出ない)
配列(vector)の大きさが0か1以上かで場合分けせよ(RE注意)
(vector<int> a(m)でm==0というものはできない)
modはなるべく最後に取れ！
*/