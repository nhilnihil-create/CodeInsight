#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int>a(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int num=0;
    for(int i=0;i<n;i++){
        num+=abs(a[i+1]-a[i]);
    }
    num+=abs(a[n]);
    vector<int>ans(n);
    for(int i=0;i<n-1;i++){
        ans[i]=num-abs(a[i+1]-a[i])-abs(a[i+2]-a[i+1])+abs(a[i+2]-a[i]);
    }
    ans[n-1]=num-abs(a[n])-abs(a[n]-a[n-1])+abs(a[n-1]);
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
}
