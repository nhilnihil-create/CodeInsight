#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n ,m, ans=0;
    cin >> n >> m;
    if(n<m) swap(n,m);
    if(n>=3 && m>=3) ans=(n-2)*(m-2);
    else if(n>1 && m==1) ans=n-2;
    else if(n==1 && m==1) ans=1;
    else ans=0;
    cout << ans;
}