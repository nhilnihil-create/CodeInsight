#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,h,w,a,b;
    cin>>n>>h>>w;
    long long int count=0;
    for (int i=0;i<n;i++) {
        cin>>a>>b;
        if (a>=h&&b>=w) {
            count++;
        }
    }
    cout<<count<<endl;
}