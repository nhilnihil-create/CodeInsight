#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long K,A,B;cin>>K>>A>>B;
    long long ans=1;
    if(B-A>2){
        ans=A;
        K-=A-1;
        ans+=(K/2)*(B-A)+K%2;
    }
    else{
        ans+=K;
    }
    cout<<ans<<endl;
}
