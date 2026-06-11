#include <bits/stdc++.h>
#include <string.h>
using namespace std;


int main(){
    long long N,i=1,j=0,ans=0;
    cin>>N;
    long long M=N;
    while(i<=N){
        i*=10;
        j++;
    }
    while(M>=1){
        ans+=(M%10);
        M/=10;
    }
    i/=10;
    if(ans<(N/i-1+(j-1)*9)){
        ans=(N/i-1+(j-1)*9);
    }
    cout<<ans<<endl;
}
