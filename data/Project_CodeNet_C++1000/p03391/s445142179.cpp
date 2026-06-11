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
#include<list>
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
    vector<ll> a,b;
    ll mi=E;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll A,B;
        cin>>A>>B;
        a.push_back(A);
        b.push_back(B);
        sum+=A;
        if(A>B){mi=min(mi,B);}
    }
    if(a==b){cout<<0<<endl; return 0;}
    cout<<sum-mi<<endl;
    
    
    
    return 0;
}
