#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string n;
    cin >> n;

    if((n[0] == n[1]) && (n[1] == n[2])) cout << n << endl;
    else{
        int v;
        v = stoi(n);
        while((n[0] != n[1]) || (n[0] != n[2])){
            v++;
            n = to_string(v);
        }
        cout << n << endl;
    }
    return 0;
}