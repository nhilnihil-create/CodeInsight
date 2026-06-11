#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int z = 0,o = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') z++;
        else o++;
    }    
    cout << min(o,z)*2 << endl;
    return 0;
}