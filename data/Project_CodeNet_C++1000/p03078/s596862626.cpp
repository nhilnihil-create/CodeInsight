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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;


int main(){
    ll x,y,z,k;
    cin>>x>>y>>z>>k;
    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    for(int i=0;i<x;i++) cin>>a[i]; sort(a.begin(),a.end());
    for(int i=0;i<y;i++) cin>>b[i]; sort(b.begin(),b.end());
    for(int i=0;i<z;i++) cin>>c[i]; sort(c.begin(),c.end());

    ll ub,lb;
    lb=0; ub=INF;
    while(ub-lb>1){
        ll m=(ub+lb)/2;
        ll cnt=0;
        bool flag=0;
        for(int i=x-1;i>=0;i--){
            for(int j=y-1;j>=0;j--){
                for(int l=z-1;l>=0;l--){
                    if(a[i]+b[j]+c[l]<m) break;
                    cnt++;
                    if(cnt>=k){
                        flag=1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag){
            lb=m;
        }else{
            ub=m;
        }
    }
    ll cnt=0;
    priority_queue<ll> q;
    for(int i=x-1;i>=0;i--){
        for(int j=y-1;j>=0;j--){
            for(int l=z-1;l>=0;l--){
                if(a[i]+b[j]+c[l]<=lb) break;
                q.push(a[i]+b[j]+c[l]);
            }
        }
    }
    for(int i=0;i<k;i++) q.push(lb);
    for(int i=0;i<k;i++){
        cout<<q.top()<<endl;
        q.pop();
    }
    return 0;
}