#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(void){
    long long n,m,i,j,ans=0;
    cin >> n >> m;
    vector<pair<long long,long long>>a(n);
    for(i=0;i<n;i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(),a.end());
    for(i=0;i<n;i++){
        long long x = min(m,a[i].second);
        ans+=x*a[i].first;
        m-=x;
        if(m==0) break;
    }
    cout << ans;
}