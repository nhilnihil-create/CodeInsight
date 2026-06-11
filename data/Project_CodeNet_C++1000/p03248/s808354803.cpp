//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

int main(){
    string s;
    cin>>s;

    bool ok=true;

    int n=s.size();

    if(s[0]=='0') ok=false;
    if(s[n-1]=='1')  ok=false;
    REP(i,n-1){
        if(s[i]!=s[n-2-i]) ok=false;
    }

    if(ok){
        queue<int> que;
        vector<pair<int,int>> ans;
        bool cur_ok=true;
        int bv=0;
        s[n-1]='1';
        REP2(i,1,n){
            if(s[i]=='1'){
                ans.push_back(make_pair(bv+1,i+1));
                bv=i;
            }
        }

        REP2(i,1,n){
            if(s[i]=='0'&&i!=n-1){
                que.push(i);
            }else{
                while(!que.empty()){
                    int v=que.front();
                    que.pop();
                    ans.push_back(make_pair(v+1,i+1));
                }
            }
        }
        REP(i,ans.size()){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }else{
        cout<<-1<<endl;
    }
}