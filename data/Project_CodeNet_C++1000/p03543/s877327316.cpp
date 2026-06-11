#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    string s;
    cin >> s;
    if(((s[0] == s[1]) && (s[1] == s[2])) ||
        ((s[1] == s[2]) && (s[2] == s[3]))){
            cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}