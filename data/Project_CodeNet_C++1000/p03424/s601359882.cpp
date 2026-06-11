#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    map<char, int> mp;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        mp[c]++;
    }
    if(mp.size() == 4) cout << "Four" << endl;
    else if(mp.size() == 3) cout << "Three" << endl;
    
    return 0;
}