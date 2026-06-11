#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n,k,i;
    long long x[100000],ans=1000000001;
    cin >> n >> k;
    for(i=0;i<n;i++) cin >> x[i];
    sort(x,x+n);
    for(i=0;i<n-k+1;i++) ans = min(ans,x[i+k-1]-x[i]);
    cout << ans;
}