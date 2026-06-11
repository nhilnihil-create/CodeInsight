#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    string s;
    cin >> s;
    int n = s.length();

    ll ans=0, b=0;
    for(int i=0; i<n; ++i){
        if(s[i] == 'B')
            b++;
        else
            ans += b;
    }

    cout << ans;
}