#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < 3; i++){
        if(s[i] == '1') sum++;
    }
    cout << sum << endl;
    return 0;
}