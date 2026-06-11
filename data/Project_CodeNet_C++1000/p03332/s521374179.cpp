#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long
#define MAX_N 300001

using namespace std;

long long MOD = 998244353;

long long fact[MAX_N];
void factorial(int N){
    fact[0]=1;
    for(int i=0; i<N; i++){
        fact[i+1]=(i+1)*fact[i]%MOD;
    }
}

map<long long, long long> inv;
long long inverse(long long x){
    if (inv.count(x)){
        return inv[x];
    }
    long long p=MOD-2;
    long long ret=1;
    long long tmp=x;
    while(p>0){
        if(p%2==1)ret=ret*tmp%MOD;
        tmp=tmp*tmp%MOD;
        p/=2;
    }
    inv[x]=ret;
    return ret;
}

long long comb(int a, int b){
    long long ret=fact[a]*inverse(fact[a-b])%MOD;
    return ret*inverse(fact[b])%MOD;
}

int main(){
    ll N, A, B, K;
    cin >> N >> A >> B >> K;

    factorial(N);

    ll ans=0;
    for(ll i=0; i<=N; i++){
        ll j=(K-i*A)/B;
        if((K-i*A)%B!=0)continue;
        if(j<0 || N<j)continue;

        ans=(ans+comb(N,i)*comb(N,j)%MOD)%MOD;
    }
    cout << ans << endl;
}