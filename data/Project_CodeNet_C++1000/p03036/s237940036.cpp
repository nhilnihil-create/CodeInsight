#include<bits/stdc++.h> 
using namespace std;

int main() {
    long long r,d,x2,x;
    cin>>r>>d>>x2;x=x2;
    for(int i=1;i<=10;i++){
        long long ans=(r*x)-d;
        cout<<ans<<endl;
        x=ans;
    }
}