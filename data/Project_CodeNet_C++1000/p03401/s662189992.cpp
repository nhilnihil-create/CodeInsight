#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main (){
    int n;
    int ans=0;
    cin >> n;
    vector<int>a(n+2);
    a[0]=0;
    a[n+1]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a[i]=x;
        ans+=abs(a[i]-a[i-1]);
    }
    ans+=abs(a[n+1]-a[n]);
    for(int i=1;i<=n;i++){
        cout << ans-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]) <<endl;
    }
    return 0;
}

