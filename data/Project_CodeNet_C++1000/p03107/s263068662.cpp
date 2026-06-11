#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
//const int MOD = 1e9+7;


int main(){
    string s;
    cin >> s;
    int c0=0, c1=0;
    for(int i=0; i<(int)s.length(); ++i){
        if(s[i]=='0')
            c0++;
        else
            c1++;
    }

    cout << 2*min(c0, c1);
}
