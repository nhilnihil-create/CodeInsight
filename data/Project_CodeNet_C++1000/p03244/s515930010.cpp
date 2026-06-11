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
ll e[MAX_N];
ll o[MAX_N];

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll e_f=0, e_s=0, o_f=0, o_s=0, e_num=0, o_num=0;
    for(ll i=0;i<n;i++){
        if(i%2==0){
            e[a[i]]++;
            if(e[a[i]]>e_f){
                if(e_num!=a[i]) e_s=e_f;
                e_f=e[a[i]];
                e_num=a[i];
            }else if(e[a[i]]>e_s){
                e_s=e[a[i]];
            }
        }else{
            o[a[i]]++;
            if(o[a[i]]>o_f){
                if(o_num!=a[i]) o_s=o_f;
                o_f=o[a[i]];
                o_num=a[i];
            }else if(o[a[i]]>o_s){
                o_s=o[a[i]];
            }
        }
    }
    if(e_num!=o_num){
        cout<<n - e_f - o_f<<endl;
    }else{
        cout<<min(n - e_f - o_s, n - e_s - o_f)<<endl;
    }
}