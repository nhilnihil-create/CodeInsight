#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,m;
    cin >> n >> m;
    if(n>m) swap(n,m);
    long long ans;
    if(n==1&&m==1) ans=1;
    else if(n==1&&m!=1) ans=m-2;
    else ans=(n-2)*(m-2);
    cout << ans << endl;
}