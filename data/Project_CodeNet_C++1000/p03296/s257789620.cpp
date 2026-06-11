#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n-1) cin>>a[i];
    int ans=0;
    rep(i,0,n-2){
        if(a[i]==a[i+1]){
            a[i+1] = 20000;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}