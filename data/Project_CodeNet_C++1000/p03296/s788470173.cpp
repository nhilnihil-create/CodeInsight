#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,tmp,count=0;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a;
        if (i!=0&&a==tmp) {
            count++;
            tmp=0;
        } else {
            tmp=a;
        }
    }
    cout<<count<<endl;
}