#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,k;
    cin>>n>>k;
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