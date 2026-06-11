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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        ll DC=0,MC=0;
        ll mid=0;
        ll ans=0;
        ll l=0;
        for(int i=0;i<n;i++){
            if(i-l==k){
                if(s[l]=='D'){mid-=MC; DC--;}
                else if(s[l]=='M'){MC--;}
                l++;
            }
            if(s[i]=='D'){DC++;}
            else if(s[i]=='M'){mid+=DC; MC++;}
            else if(s[i]=='C'){ans+=mid;}
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
