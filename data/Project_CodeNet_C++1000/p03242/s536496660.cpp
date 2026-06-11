#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef vector<int> VI;
typedef vector<ll> VLL;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
    string s;
    cin >> s;

    rep(i,3){
        if(s[i] == '1')s[i] = '9';
        else if(s[i] == '9')s[i] = '1';
    }

    cout << s << endl;
    return 0;
}