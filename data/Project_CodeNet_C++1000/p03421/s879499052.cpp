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
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
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
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> A(n);
    if(a+b>n+1 || a*b<n){cout<<-1<<endl; return 0;}
    else if(a+b==n+1){
        for(int i=0;i<a;i++){A[i]=n-a+i+1;}
        for(ll i=a;i<n;i++){A[i]=n-a-(i-a);}
    }
    else{
        ll bef=n+1;
        for(ll i=0,t=0;i<n;t++){
            ll dist=min(n-i-(b-t-1),a);
            for(ll t=0;t<dist;t++){A[i+t]=bef-dist+t;}
            bef-=dist;
            i+=dist;
        }
    }
    for(int i=0;i<n;i++){
        cout<<A[i];
        if(i+1!=n){cout<<" ";}
    }
    cout<<endl;
    
    return 0;
}
