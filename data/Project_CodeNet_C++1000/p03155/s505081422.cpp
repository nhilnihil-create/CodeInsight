#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,h,w,H=0,W=0;
    cin>>n>>h>>w;
    if (n==h) {
        H=1;
    } else {
        for (int i=h;i<=n;i++) {
            H++;
        }
    }
    if (n==w) {
        W=1;
    } else {
        for (int i=w;i<=n;i++) {
            W++;
        }
    }
    cout<<H*W<<endl;
}