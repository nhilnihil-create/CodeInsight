#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>alp(26,0);
    for(int i=0;i<n;i++){
        alp[(int)(s[i]-'a')]++;
    }
    long ans = 1;
    long const MOD = 1e9+7;
    for(int i=0;i<26;i++){
        ans *= alp[i] + 1;
        ans %= MOD;
    }
    cout <<ans-1<<endl;
    
}