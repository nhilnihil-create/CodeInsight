#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
using namespace std;
#define INF 1LL<<62
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());
//#define int ll

signed main(){
    int L;
    cin>>L;
    int n=0;
    int t=1;
    while(t<=L){
        n++;
        t*=2;
    }
    t/=2;
    cout<<n<<" "<<(int)__builtin_popcount(L)-1+(n-1)*2<<endl;
    t=1;
    for(int i=1;i<=n-1;i++){
        cout<<i<<" "<<i+1<<" "<<0<<endl;
        cout<<i<<" "<<i+1<<" "<<t<<endl;
        t*=2;
    }
    int sum=0;
    int s=1;
    for(int i=1;i<=n-1;i++){
        if(bit(L,i-1)){
            cout<<i<<" "<<n<<" "<<t<<endl;
            t+=sum+1;
        }
        sum+=s;
        s*=2;
    }

}
