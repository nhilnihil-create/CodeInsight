#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    map<int,int> mp;
    for(int i = 0; i < 3; i++){
        int a, b; cin >> a >> b; mp[a]++; mp[b]++;
    }
    int cn1 = 0, cn2 = 0;
    for(auto i : mp) {
        cn1 += i.second == 1;
        cn2 += i.second == 2;
    }
    cout << (cn1 == 2 && cn2 == 2 ? "YES" : "NO") << endl;
}