#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;


int main(){
    int n,ans;
    cin>>n;
    cin>>ans;
    n--;
    while(n--){
        int a;
        cin>>a;
        ans = __gcd(a,ans);
    }
    cout<<ans;
}