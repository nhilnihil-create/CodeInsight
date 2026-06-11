#include<bits/stdc++.h>
#define D 1000000007
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    string s; cin >> s;

    ll ans = 1;
    ll alpha[26] = {0};

    for(int i=0; i<n; i++){
        alpha[s[i] - 'a']++;
        alpha[s[i] - 'a'] %= D;
    }
    for(int i=0; i<26; i++){
        ans *= (alpha[i]+1);
        ans %= D;
    }
    ans = ans - 1;
    cout<< ans << endl;
    return 0;
}