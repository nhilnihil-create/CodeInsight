#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,k;
    cin >> n >> k;
    int l,r;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x==1) l=i+1;
    }
    r=n-l+1;
    int ans=0;

    if(n==k){
        ans =1;
    }
    else if(l<=k || r<=k){
        n -= k;
        ans ++;
        ans += (n-1)/(k-1)+1;
    }
    else{
        n--;
        ans += n/(k-1);
    }

    cout << ans << endl;

    return 0;
}