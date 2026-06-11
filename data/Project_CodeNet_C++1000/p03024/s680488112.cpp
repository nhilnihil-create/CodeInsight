#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int k = s.size();
    int cnt = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == 'o') cnt++;
    }
    if(15-k+cnt >= 8) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}