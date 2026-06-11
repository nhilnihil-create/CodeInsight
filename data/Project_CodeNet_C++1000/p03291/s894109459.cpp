/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

const int mod = 1e9+7;

string s;
string form = "ABC";


int cntC[N];
int cntA[N];
int cntQ[N];
int Lways[N];
int Rways[N];

void add_self(int & a , int b){
    a += b;
    a %= mod;
}

int fastP(int b, int e){
    if(!e)
        return 1;
    if(e & 1)
        return b * 1ll * fastP(b * 1ll * b % mod, e >> 1) % mod;
    return fastP(b * 1ll * b % mod, e >> 1) % mod;
}

int main(){
    cin >> s;
    int n = s.size();
    int ways = 0;
    cntA[0] = (s[0] == 'A');
    cntQ[0] = (s[0] == '?');
    cntC[0] = (s[0] == 'C');
    for(int i = 1; i < n; i++){
        cntA[i] = (s[i] == 'A') + cntA[i - 1];
        cntQ[i] = (s[i] == '?') + cntQ[i - 1];
        cntC[i] = (s[i] == 'C') + cntC[i - 1];
    }
    for(int i = 1; i < n; i++){
        if(s[i] == 'B' || s[i] == '?'){
            Lways[i] = 1ll * cntA[i - 1] * fastP(3 , cntQ[i - 1]) % mod;
            if(cntQ[i - 1]){
                add_self(Lways[i] , 1ll * cntQ[i - 1] * fastP(3 , cntQ[i - 1] - 1) % mod);
            }
        }
    }
    for(int i = n - 1; i > 0; i--){
        if(s[i] == 'B' || s[i] == '?'){
            Rways[i] = 1ll * (cntC[n - 1] - cntC[i]) * fastP(3 , cntQ[n - 1] - cntQ[i]) % mod;
            if(cntQ[n - 1] - cntQ[i]){
                add_self(Rways[i] , 1ll * (cntQ[n - 1] - cntQ[i]) * fastP(3 , (cntQ[n - 1] - cntQ[i]) - 1) % mod);
            }
        }
    }
    for(int i = 0; i < n; i++){
        add_self(ways , 1ll * Lways[i] * Rways[i] % mod);
    }
    cout << ways << endl;
}
