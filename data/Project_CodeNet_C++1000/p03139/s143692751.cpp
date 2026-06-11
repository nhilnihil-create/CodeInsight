#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<min(a,b)<<" ";
    if (a+b>=n) {
        cout<<(a+b)-n;
    } else {
        cout<<0;
    }
    cout<<endl;
}