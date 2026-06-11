#include <bits/stdc++.h>
using namespace std;  

int main(){
    map<int, int> mp;
    int s, i;
    cin >> s;
    
    i = 1;
    while (mp[s] != 1) {
        mp[s] = 1;
        s = (s%2 == 0 ? s/2 : 3*s + 1);
        i++;
    }
    
    cout << i << endl;
    return (0);
}