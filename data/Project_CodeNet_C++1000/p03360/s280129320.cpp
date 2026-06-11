#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int A,B,C;cin>>A>>B>>C;
    int K;cin>>K;
    if(A>=B && A>=C) A*=pow(2,K);
    else if(B>=A && B>=C) B*=pow(2,K);
    else C*=pow(2,K);

    cout<<A+B+C<<endl;
}