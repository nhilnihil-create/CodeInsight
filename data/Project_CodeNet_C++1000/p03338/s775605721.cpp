#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans=0;
    for (int i=1; i<n-1; i++){
        int common=0;
        int cnt_f[26], cnt_b[26];
        for (int j=0; j<26; j++) cnt_f[j] = cnt_b[j] = 0; 
        for (int j=0; j<i; j++) cnt_f[s[j]-'a'] += 1;
        for (int j=0; j<n-i; j++) cnt_b[s[n-1-j]-'a'] += 1;
        for (int j=0; j<26; j++) {if (cnt_f[j]*cnt_b[j] > 0) common += 1;}
        ans = max(ans, common);
    }
    cout << ans << endl;
    return 0;    
}