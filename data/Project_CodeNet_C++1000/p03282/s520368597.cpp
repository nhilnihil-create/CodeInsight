#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e15;

int main(){

    string s;
    cin >> s;
    ll k;
    cin >> k;

    char a, b;
    int pos;
    a = s.at(0);
    if (s.size()>1){
        for (int i=1; i<s.size(); i++){
            b = s.at(i);
            pos = i;
            if (b != '1') break;
        }
    }

    if ((a == '1') && (pos+1<=k)) cout << b << endl;
    else cout << a << endl;

    return 0;
}