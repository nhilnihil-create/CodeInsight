#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int lose = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'x') lose += 1;
    }

    if(lose < 8) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}