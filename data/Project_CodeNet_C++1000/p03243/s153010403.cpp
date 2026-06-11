#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int N;cin>>N;
    if(N%111==0) cout<<N<<endl;
    else{
        cout<<((N/111)+1)*111<<endl;
    }
}