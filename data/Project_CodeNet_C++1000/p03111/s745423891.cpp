#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;

vector<int> decode(ll a,ll N){
    vector<int> ret(N);
    for(int i=0;i<N;i++){
        ret[i]=a%4;
        a/=4;
    }
    
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N,A,B,C;
    cin>>N>>A>>B>>C;
    vll l(N);
    for(ll i=0;i<N;i++)cin>>l[i];
    
    ll ans=LLMAX;
    ll count_max=pow(4,N);
    for(ll count=0;count<count_max;count++){
        vector<int> p=decode(count,N);
        vvll split(4);
        for(int i=0;i<N;i++){
            split[p[i]].push_back(l[i]);
        }
        
        bool continue_loop=false;
        for(int i=0;i<3;i++){
            if(split[i].size()==0) continue_loop=true;
        }
        if(continue_loop)continue;
        
        ll cost=0;
        for(int i=0;i<3;i++){
            cost+=10*(split[i].size()-1);
            ll sum=0;
            for(int j=0;j<split[i].size();j++){
                sum+=split[i][j];
            }
            if(i==0) cost+=abs(A-sum);
            if(i==1) cost+=abs(B-sum);
            if(i==2) cost+=abs(C-sum);
        }
        if(cost<ans)ans=cost;
    }
    cout<<ans<<endl;
    
    return 0;
}
