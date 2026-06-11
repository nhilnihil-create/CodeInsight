#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
#define F first
#define S second
#define MK make_pair
const ll E=1e17+7;
const ll MOD=1000000007;

bool done[110000]={};

int main(){
    ll k;
    cin>>k;
    priority_queue<pll,vector<pll>,greater<pll>> q; //cost,mod
    q.push({1,1});
    ll ans=-1;
    while(!q.empty()){
        pll p=q.top();
        q.pop();
        if(done[p.S]){continue;}
        done[p.S]=true;
        
        if(p.S*10%k==0){ans=p.F; break;}
        if((p.S+1)%k==0){ans=p.F+1; break;}
        q.push({p.F+1,(p.S+1)%k});
        if(p.S*10%k!=p.S){
            q.push({p.F,p.S*10%k});
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}

