#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k;
    string s;
    cin >> s >> k;

    int i = 0;
    int n;
    while((n = s[i] - '0') == 1){
        if(k == i + 1){
            cout << 1 << endl;
            return 0;
        }
        i++;
    }
    cout << n << endl;
    return 0;
}