#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A,B,C,K;
    cin>>A>>B>>C>>K;
    long long ans;

    if(K % 2 == 0) ans = A - B;
    else if(K % 2 != 0) ans = B - A;

    cout<<ans<<endl;

    return 0;

}