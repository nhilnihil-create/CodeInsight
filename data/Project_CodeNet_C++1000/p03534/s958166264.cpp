#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int cnta = 0, cntb = 0, cntc = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a') cnta++;
        if(s[i] == 'b') cntb++;
        if(s[i] == 'c') cntc++;
    }
    int cntmax = max(cnta, max(cntb, cntc));
    if(cntmax - cnta <= 1 && cntmax - cntb <= 1 && cntmax - cntc <= 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}