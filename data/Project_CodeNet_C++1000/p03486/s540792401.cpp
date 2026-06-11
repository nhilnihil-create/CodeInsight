#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    string s , t;
    cin >> s >> t;

    sort(s.begin() ,s.end());
    sort(t.begin() ,t.end(),greater<char>());

    if(s == t){
        cout << "No" << endl;
        return 0;
    }

    vector<string> S(2);
    S[0] = s,S[1] = t;
    sort(S.begin(),S.end());

    if(S[0] == s){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}
