#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //GCC5.4.1で配列の範囲外アクセスをエラーにする

//cmdで g++ test.cpp とするとコンパイルできる
//制限1秒なら10^6は余裕 10^7は多分間に合う 10^8はよほど単純でないと厳しい
// https://github.com/atcoder/live_library
// cppdbg: test.exeのterminalに標準入力を打てる

#define ALL(x) x.begin(),x.end()
#define get_tp(t,i) get<i>(t)
#define len(x) (ll)(x.size())
#define ub(a,x) (upper_bound(ALL(a),x)-a.begin())
#define lb(a,x) (lower_bound(ALL(a),x)-a.begin())
typedef long long ll; //long long
typedef pair<int,int> pii; //pair<int,int>
typedef pair<long long,long long> pllll; //pair<ll,ll>
typedef vector<int> vi; //vector<int>
typedef vector<vector<int>> vvi; //vector<vector<int>>
typedef vector<ll> vll; //vector<long long>
typedef vector<vector<ll>> vvll; //vector<vector<long long>>
typedef priority_queue<ll, vector<ll>, greater<ll> > gpq; //逆順priority_queue
typedef priority_queue<ll> pq;

//const int MOD=998244353;
const int MOD=1000000007; //10^9+7
const long double PI=3.1415926535897932;


const ll MAX_PDEC=1000000;
vector<ll> D(MAX_PDEC);
void make_prime_list(){
    for(ll i=1;i<=1000000;i++)D[i]=i;
    for(ll i=2;i<=1000000;i++){
        for(ll j=i;j<=1000000;j+=i){
            D[j]=min(D[j],i);
        }
    }
}

void prime_decomposition(ll N,vector<int> &ans){
    ans.clear();
    ll v=N;
    while(v>1){
        ans.push_back(D[v]);
        v/=D[v];
    }
}

void ans2vecpair(vector<int> ans,vector<pii> &p){
    p.clear();
    for(int i=0;i<ans.size();i++){
        if(p.size()==0){
            p.push_back(make_pair(ans[i],1));
        }else if(p[p.size()-1].first==ans[i]){
            p[p.size()-1].second++;
        }else{
            p.push_back(make_pair(ans[i],1));
        }
    }
}

int main(){
    vi ans(0);
    vector<pii> p(0);
    make_prime_list();

    int N;cin>>N;
    int out=0;
    for(int i=1;i<=N;i+=2){
        prime_decomposition(i,ans);
        ans2vecpair(ans,p);
        int dcount=1;
        for(int j=0;j<p.size();j++){
            dcount*=p[j].second+1;
        }
        if(dcount==8)out++;
    }
    cout<<out<<endl;
}