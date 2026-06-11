#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()    
{
    int n;
    cin>>n;
    int ans = 0;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n;i++){
        if(a[i]>b[i]) ans += (a[i]-b[i]);
    }
    cout<<ans;
}