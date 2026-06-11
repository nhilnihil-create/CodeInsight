#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    char b;
    cin >> b;
    
    if(b == 'A') cout << "T" << endl;
    else if(b == 'T') cout << "A" << endl;
    else if(b == 'C') cout << "G" << endl;
    else if(b == 'G') cout << "C" << endl;

    return 0;
}