#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    if(n==1){
        if(m>2){
            cout<<m-2<<endl;
        }
        if(m==1){
            cout<<1<<endl;
        }
        if(m==2){
            cout<<0<<endl;
        }
        return 0;
    }
    if(m==1){
        if(n>2){
            cout<<n-2<<endl;
        }
        if(n==1){
            cout<<1<<endl;
        }
        if(n==2){
            cout<<0<<endl;
        }
        return 0;
    }
    ans=(m-2)*(n-2);
    cout<<ans<<endl;

}