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
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=1<<18;

ll gcd(ll a,ll b){
    ll M=max(a,b);
    ll m=min(a,b);
    if(m==0){
        return M;
    }
    return gcd(m,M%m);
}


int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll g=a[0];
    for(int i=1;i<n;i++){
        g=gcd(g,a[i]);
    }
    cout<<g<<endl;

}