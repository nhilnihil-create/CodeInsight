#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,M;
    cin>>N>>M;

    long long ans = N*M;

    if(N == 1 || M == 1){
        if(N == 1 && M == 1) ans = 1;
        else ans = N*M-2;
    }

    else ans = N*M-2*(N+M-2);

    cout<<ans<<endl;

    return 0;
}