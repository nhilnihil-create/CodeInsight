#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    char s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    long long a=1e9+7;
    long long cnt[26];
    for(int i=0;i<26;i++) cnt[i]=0;
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }
    long long ret=1;
    for(int i=0;i<26;i++){
        ret=ret*(1+cnt[i])%a;
    }
    cout << (ret+a-1)%a << endl;
}