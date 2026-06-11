#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int p[n];
    for (int i = 0;i<n;i++){
        cin>>p[i];
    }
    int ans =0;
    sort(p,p+n);
    for (int i = 0;i<n-1;i++){
        ans+=p[i];
    }
    ans+=p[n-1]/2;
    cout<<ans;

    
}
