#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,k; cin>>a>>b>>c>>k;
    int d = max(a,max(b,c));
    long long ans = a+b+c-d;
    ans += d*pow(2,k);
    cout << ans << endl;
}