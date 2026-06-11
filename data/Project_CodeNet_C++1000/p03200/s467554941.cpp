#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    string s;
    cin >> s;
    int n = s.length();

    ll ans=0;
    vector<int> b(n);
    if(s[0] == 'B'){
        b[0] = 1;
    }

    for(int i=1; i<n; ++i){
        if(s[i] == 'W'){
            b[i] = b[i-1];
            ans += b[i];
        }
        else
            b[i] = b[i-1]+1;
    }

    cout << ans;
}
