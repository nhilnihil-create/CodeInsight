#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,x;
    cin>>a>>b>>x;
    int flag=0;
    for (int i=0;i<=b;i++) {
        if (a+i==x) {
            cout<<"YES"<<endl;
            flag=1;
            break;
        }
    }
    if (flag==0) {
        cout<<"NO"<<endl;
    }
}
