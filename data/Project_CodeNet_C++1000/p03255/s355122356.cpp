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




int main(int argc, char const *argv[]) {
    long long n,x;cin>>n>>x;
    vector<long long> a(n);
    vector<long long> b(n+1,0);
    long long su = 0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        su += a[i];
        b[i+1] = su;
    }
    long long res = 1ll<<62;
    for(long long k=n;k>0;--k){
        long long tmp = (n+k)*x;
        if(tmp>res)continue;
        long long i = 0;
        while(true){
            long long r = n - i*k, l = n - (i+1)*k;
            if(l<0)l=0;
            long long f = 2*i + 3;
            if(i==0)f = 5;
            tmp += f*(b[r]-b[l]);
            if(l==0)break;
            i++;
            if(tmp>res)break;
        }
        res = min(res,tmp);
    }
    cout<<res<<endl;
    return 0;
}