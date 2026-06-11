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
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;






    
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    map<ll,ll> M;
    for(int i=0;i<n;i++){
        cin>>a[i];
        M[a[i]]=i+1;
    }
    sort(a.begin(),a.end(),greater<ll>());
    vector<ll> parent(n,-1);
    vector<ll> count(n,1);
    vector<ll> cost(n,0);
    for(int i=0;i+1<n;i++){
        ll to=a[i]-n+count[i]*2;
        ll I=lower_bound(a.begin(),a.end(),to,greater<ll>())-a.begin();
        if(I==n || a[I]!=to){cout<<-1<<endl; return 0;}
        count[I]+=count[i];
        cost[I]+=cost[i]+count[i];
        parent[i]=I;
    }
    if(cost[n-1]!=a[n-1]){cout<<-1<<endl; return 0;}
    for(int i=0;i<n-1;i++){
        cout<<M[a[i]]<<" "<<M[a[parent[i]]]<<endl;
    }
    
    
        
    return 0;
}
