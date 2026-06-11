#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#define Fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define rep(i, n) for(i=0; i<n; i++)
using namespace std;
int main() {
    Fast;
    string s;
    ll k;
    cin >> s;
    cin >> k;
    ll i;
    //int len = s.length();
    rep(i, k){
        if(s[i]=='1') continue;
        else{
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "1\n";
    return 0;
}