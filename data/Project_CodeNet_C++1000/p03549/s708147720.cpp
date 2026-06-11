#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int N,M;cin>>N>>M;
    int cnt;
    cnt=100*(N-M)+1900*M;
    cnt*=pow(2,M);
    cout<<cnt<<endl;
}