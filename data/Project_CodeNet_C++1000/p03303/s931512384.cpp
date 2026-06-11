#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(std::string S, long long w){
    string ans;
    ll n=S.length();
    for(ll i=0; (i*w) <n; i++){
        ans.push_back(S[i*w]);
    }
    cout << ans << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    long long w;
    scanf("%lld",&w);
    solve(S, w);
    return 0;
}
