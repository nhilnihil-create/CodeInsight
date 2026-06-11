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
    int N,K;
    cin>>N>>K;
    vector<vector<ll>> neta(N+1);
    priority_queue<tuple<ll,int,int>> que;
    priority_queue<ll,vector<ll>,greater<ll>> que2;
    ll d;
    int t;
    vector<int> vec_t(N);
    vector<ll> vec_d(N);
    REP(i,N){
        cin>>t>>d;
        vec_t[i]=t;
        vec_d[i]=d;
        que.push(make_tuple(d,t,i));
    }

    tuple<ll,int,int> p;
    int cnt=0;
    ll ans=0;
    int num;
    REP(i,K){
        p=que.top();
        que.pop();
        d=get<0>(p);
        t=get<1>(p);
        num=get<2>(p);
        if(neta[t].size()==0) cnt++;
        neta[t].push_back(d);
        ans+=d;
    }
    ans+=pow(cnt,2);

    ll tmp=ans;
    REP(i,N){
        REP2(j,1,neta[i].size()){
            que2.push(neta[i][j]);
        }
    }

    ll q;
    while(!que2.empty()&&!que.empty()){
        q=que2.top();
        que2.pop();
        tmp-=q;
        bool flag=false;
        while(!que.empty()){
            p=que.top();
            que.pop();
            d=get<0>(p);
            t=get<1>(p);
            num=get<2>(p);
            if(neta[t].size()==0){
                neta[t].push_back(num);
                tmp+=d;
                flag=true;
                break;
            }
            
        }
        if(flag){
            tmp+=(2*cnt+1);
            cnt++;
            ans=max(tmp,ans);
        }
    }
    cout<<ans<<endl;

}