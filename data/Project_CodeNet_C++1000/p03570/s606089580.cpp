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

vector<int> A(1LL<<26,MOD);

int main(){
    string s;
    cin>>s;
    int n=(int)s.size();
    vector<ll> count(n+1,0);
    for(int i=1;i<=n;i++){
        (count[i]=count[i-1])^=1LL<<(s[i-1]-='a');
    }
    int ans=0;
    A[0]=0;
    for(int i=1;i<=n;i++){
        ans=A[count[i]]+1;
        for(ll t=0;t<26;t++){
            ans=min(ans,A[count[i]^(1LL<<t)]+1);
        }
        A[count[i]]=min(ans,A[count[i]]);
    }
    cout<<ans<<endl;
    
    
    return 0;
}
