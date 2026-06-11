#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    string s; cin >> s;
    ll ans = 1;
    ll ch[30];
    for(int i = 0; i < 30; i++) ch[i] = 0;
    for(int i = 0; i < n; i++) ch[s[i] - 'a']++;
    int sum = 0;
    for(int i = 0; i < 30; i++){
        sum += ch[i];
        if(ch[i] > 0) ans = (ans * (ch[i]+1)) %mod;
    }
    cout << (ans-1)%mod << endl;
    

    return 0;
}