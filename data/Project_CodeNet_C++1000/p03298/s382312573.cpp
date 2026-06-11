#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string substring(int L, string S, ull mask){
    string s="",r="";
    for(int i=0;i<L;i++){
        if((1<<i)&mask) s+=S[i];
        else r+=S[i];
    }
    return s+","+r;
}

int main(){
    int N;
    string S;
    cin >> N >> S;

    string A,B;
    A=S.substr(0,N);
    B="";
    for(int i=1;i<=N;i++){
        B=B+S[2*N-i];
    }

    map<string,ll> cA,cB;
    for(ull m=0;m<(1<<N);m++){
        cA[substring(N,A,m)]++;
        cB[substring(N,B,m)]++;
    }

    ll ans=0;
    for(auto x : cA){
        ans+=x.second*cB[x.first];
    }

    cout << ans << endl;

    return 0;
}