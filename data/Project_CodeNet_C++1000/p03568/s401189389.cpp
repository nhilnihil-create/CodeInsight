#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a;
    cin>>n;
    int all=pow(3,n);
    int tmp=1;
    for (int i=0;i<n;i++) {
        cin>>a;
        if (a%2==1) {
            tmp*=1;
        } else {
            tmp*=2;
        }
    }
    cout<<all-tmp<<endl;
}