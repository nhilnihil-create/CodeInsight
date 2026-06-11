#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m;
    cin>>n>>m;
    if (n<m) {
        if (n==1) {
            cout<<n*m-2<<endl;
        } else if (n==2) {
            cout<<0<<endl;
        } else {
            cout<<(n-2)*(m-2)<<endl;
        }
    } else if (n>m) {
        if (m==1) {
            cout<<n*m-2<<endl;
        } else if (m==2) {
            cout<<0<<endl;
        } else {
            cout<<(n-2)*(m-2)<<endl;
        }
    } else {
        if (n==1&&m==1) {
            cout<<1<<endl;
        } else if (n==2&&m==2) {
            cout<<0<<endl;
        } else {
            cout<<(n-2)*(m-2)<<endl;
        }
    }
}