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
#include<math.h>
#include<numeric>
#include<cassert>
#include<random>
#include<deque>
#include<chrono>
#include<unordered_map>
#include<list>
#include<fstream>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
const ll E=1e18+7;
#define F first
#define S second
#define MK make_pair
const ll MOD=1000000007;






int main(){
    ll n;
    cin>>n;
    vector<ll> l(n),r(n);
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    l.push_back(0);
    r.push_back(0);
    sort(r.begin(),r.end());
    sort(l.begin(),l.end(),greater<ll>());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,ans+l[i]-r[i]);
        
    }
    cout<<ans*2<<endl;
    
    
    
    
    
    return 0;
}
