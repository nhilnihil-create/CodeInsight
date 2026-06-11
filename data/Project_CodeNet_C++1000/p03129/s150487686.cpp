#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,k;
    cin>>n>>k;
    if (n==1&&k==1) {
        cout<<"YES"<<endl;
    } else if (n<=k) {
        cout<<"NO"<<endl;
    } else {
        int count=0;
        for (int i=1;i<=n;i+=2) {
            count++;
        }
        if (count>=k) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}