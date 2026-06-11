/**
*    author:  souzai32
*    created: 01.08.2020 22:48:50
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    string s;
    cin >> s;
    int n=s.size();
    vector<char> key(7);
    bool ans=false;

    for(int i=0; i<=7; i++){
        for(int k=0; k<i; k++){
            key.at(k)=s.at(k);
        }
        for(int k=0; k<7-i; k++){
            key.at(i+k)=s.at(n-7+i+k);
        }
        if(key.at(0)=='k'&&key.at(1)=='e'&&key.at(2)=='y'&&key.at(3)=='e'&&key.at(4)=='n'&&key.at(5)=='c'&&key.at(6)=='e') ans=true;
        if(ans) break;
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}