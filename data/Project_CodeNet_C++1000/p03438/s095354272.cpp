#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long i = 0; i < (long)(n); i++)
int main(){
    long n,cost=0,cost1=0,sum=0;
    cin >> n;
    long a[n],b[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n){
        sum += b[i]-a[i];
        if(b[i]-a[i]>0) cost+=(b[i]-a[i]+1)/2;
        else  cost1 += a[i]-b[i];
    }
    if(max(cost1,cost)<=sum) cout << "Yes" << endl;
    else cout << "No" << endl;
}