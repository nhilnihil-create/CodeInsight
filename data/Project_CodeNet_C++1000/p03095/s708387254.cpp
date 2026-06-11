/**
*    author:  souzai32
*    created: 04.08.2020 19:53:05
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    string s;
    cin >> n >> s;
    vector<long long int> alphabet(26,1);
    long long int ans=1;

    rep(i,n) alphabet.at(s.at(i)-'a')++;
    rep(i,26){
        ans*=alphabet.at(i);
        ans%=1000000007;
    }

    cout << ans-1 << endl;

    return 0;
}