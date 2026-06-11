#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long D,N;cin>>D>>N;
    if(N==100){
        long long ans=pow(100,D);
        ans*=N+1;
        cout<<ans<<endl;
    }
    else{
        cout<<pow(100,D)*N<<endl;
    }
    return 0;
}
