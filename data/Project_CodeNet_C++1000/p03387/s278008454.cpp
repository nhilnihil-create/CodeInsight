#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

void slove(){
    int a[3];
    cin >> a[0]>>a[1]>>a[2];
    sort(a,a+3);
    int ans = 0;
    if((a[1] - a[0])%2){
        a[2]++;
        a[0]++;
        ans++;
    }
    ans += (a[1] - a[0])/2;
    int x = a[2] - a[1];
    if(x%2) ans++;
    ans+=(x/2)*2;
    cout<<ans<<endl;
}

int main(){
    cin.tie(0);
    slove();
    return 0;
}