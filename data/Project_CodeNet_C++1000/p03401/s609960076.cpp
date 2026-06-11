#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a[n+2];
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[n+1]=0;
    long long count=0;
    for(int i=1;i<=n+1;i++){
        count+=abs(a[i]-a[i-1]);
    }
    for(int i=1;i<=n;i++){
        long long ans=count;
        ans=ans-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]);
        cout << ans << endl;
    }
}