#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    long long N,K;
    cin>>N>>K;
    long long ans=0;
    ans=(N/K)*(N/K)*(N/K);
    long long p=0;
    if(2*N<K){
        cout << 0<< endl;
        return 0;
    }
    if(K%2==0){
        p=(2*N-K)/(2*K);
        p++;
    }
    ans=ans+(p*p*p);
    cout << ans << endl;
    return 0;
}