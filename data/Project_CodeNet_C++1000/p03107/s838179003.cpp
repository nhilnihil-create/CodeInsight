#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int main(){
    string S;
    cin >> S;
    int v_0 = 0, v_1 = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S.at(i) == '0') v_0++;
        else v_1++;
    }
    
    cout << min(v_0, v_1) * 2 << endl;
    return 0;
}