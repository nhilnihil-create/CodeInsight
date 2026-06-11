#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, N) for (int i = 0; i < (N); i++)
 
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int r = 0;
    for (int i = 0; i < n;i++){
        if(s[i]=='R')
            r++;
    }
    if(r>n/2)
        cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;
}