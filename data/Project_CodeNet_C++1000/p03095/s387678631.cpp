#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = ll(1e9)+7;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll num[26] ={};
    for(int i=0;i<N;i++){
        num[S[i] -'a']++;
    }
    ll ans =1;
    for(int i=0;i<26;i++){
        ans *= (num[i]+1);
        ans %=MOD;
    }
    cout << (ans+MOD-1)%MOD << endl;
    return 0;
}