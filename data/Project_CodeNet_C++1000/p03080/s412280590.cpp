#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') r++;
    }    
    if(n/2 < r) cout << "Yes" << endl;
    else cout << "No" << endl;
}