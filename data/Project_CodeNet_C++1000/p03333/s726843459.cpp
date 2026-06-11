#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 998244353;


int main(int argc, char const *argv[]) {
    int n;cin>>n;
    vector<pair<long long, int>> l(n),r(n);
    vector<long long>l2(n+1,0),r2(n+1,0);
    for(int i=0;i<n;++i){
        long long ll,rr;cin>>ll>>rr;
        l[i] = pair<long long, int>(ll,i);
        r[i] = pair<long long, int>(rr,i);
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    for(int i=0;i<n;++i){
        l2[i+1] = l2[i] + l[n-i-1].first;
        r2[i+1] = r2[i] + r[i].first;
    }
    long long res = 0;
    for(int i=0;i<n;++i){
        res = max(res,2*(l2[i+1]-r2[i+1]));
    }
    for(int i=1;i<n;++i){
        res = max(res,2*(l2[i]-r2[i+1]));
        res = max(res,2*(l2[i+1]-r2[i]));
    }
    cout<<res<<endl;
    // long long res1 = 0,res2 = 0;
    // long long k = 0;
    // for(int i=0;i<n;++i){
    //     res1 += abs(k - min(k,r[i].first));
    //     if(i!=0&&k<=r[i].first)break;
    //     k = min(k,r[i].first);
    //     res1 += abs(k - max(k,l[n-i-1].first));
    //     if(k>=l[n-i-1].first)break;
    //     k = max(k,l[n-i-1].first);
    // }
    // res1 += k;
    // k = 0;
    // for(int i=0;i<n;++i){
    //     res2 += abs(k - max(k,l[n-i-1].first));
    //     if(i!=0&&k>=l[n-i-1].first)break;
    //     k = max(k,l[n-i-1].first);
    //     res2 += abs(k - min(k,r[i].first));
    //     if(k<=r[i].first)break;
    //     k = min(k,r[i].first);
    // }
    // res2 += k;
    // cout<<max(res1,res2)<<endl;
    return 0;
}