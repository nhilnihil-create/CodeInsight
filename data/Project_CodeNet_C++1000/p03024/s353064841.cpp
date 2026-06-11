#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    int l = 0;
    cin >> s;
    for(int i = 0;i < s.size();i ++){
        if(s[i]=='x') l ++;
    }
    if(l>7) cout << "NO" << endl;
    else cout << "YES" << endl; 
    return 0;
}