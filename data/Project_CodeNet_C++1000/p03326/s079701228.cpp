#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //GCC5.4.1で配列の範囲外アクセスをエラーにする

//cmdで g++ test.cpp とするとコンパイルできる
//制限1秒なら10^6は余裕 10^7は多分間に合う 10^8はよほど単純でないと厳しい

#define ALL(x) x.begin(),x.end()
#define get_tp(t,i) get<i>(t)
#define len(x) (ll)(x.size())
typedef long long ll; //long long
typedef pair<int,int> pii; //pair<int,int>
typedef pair<long long,long long> pllll; //pair<ll,ll>
typedef vector<int> vi; //vector<int>
typedef vector<vector<int>> vvi; //vector<vector<int>>
typedef vector<ll> vll; //vector<long long>
typedef vector<vector<ll>> vvll; //vector<vector<long long>>
typedef priority_queue<int, vector<int>, greater<int> > gpq; //逆順priority_queue
typedef priority_queue<int> pq;

//const int MOD=998244353;
const int MOD=1000000007; //10^9+7
const long double PI=3.1415926535897932;

int main(){
    int N,M;
    cin>>N>>M;
    vector<tuple<ll,ll,ll>> cake(N);
    for(int i=0;i<N;i++){
        ll x,y,z;cin>>x>>y>>z;
        cake[i]=make_tuple(x,y,z);
    }
    
    ll ans;
    for(int p=0;p<8;p++){
        vll score(N);
        for(int i=0;i<N;i++){
            score[i]=get_tp(cake[i],0)*((p&1)?1:-1);
            score[i]+=get_tp(cake[i],1)*((p&2)?1:-1);
            score[i]+=get_tp(cake[i],2)*((p&4)?1:-1);
        }
        sort(ALL(score));
        reverse(ALL(score));
        ll sum=0;
        for(int i=0;i<M;i++){
            sum+=score[i];
        }
        if(p==0){
            ans=sum;
        }else{
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}