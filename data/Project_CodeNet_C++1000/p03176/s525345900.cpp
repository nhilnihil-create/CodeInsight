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
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=4999999996000000001;
const int SEG_LEN=1<<20;
ll seg[2*SEG_LEN];


void update(int ind, ll v){
    ind+=SEG_LEN;
    seg[ind]=v;
    while(true){
        ind/=2;
        if(ind==0) break;
        seg[ind]=max(seg[ind*2],seg[ind*2+1]);
    }
}

ll get(int l, int r){
    ll res=0;
    l+=SEG_LEN; 
    r+=SEG_LEN;
    while(r-l>0){
        if(l%2==1){
            res=max(res,seg[l]);
            l++;
        }
        l/=2;
        if(r%2==1){
            r--;
            res=max(res,seg[r]);
        }
        r/=2;
    }
    return res;
}


int main(){
    int n;
    cin>>n;
    vector<ll> h(n),a(n);
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++){
        ll M=get(0, h[i]+1);
        update(h[i],M+a[i]);
    }

    cout<<get(0,n+1)<<endl;

}