#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 

int main() {
    string s;
    cin >> s;
    if(s[0]!='A'){
        cout << "WA" <<endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 2;i<s.size()-1;++i){
         if(s[i]=='C')
         cnt++;
         
    }
    if(cnt !=1) {
        cout << "WA" <<endl;
        return 0;
    }
    int mini = 0;
    for(int i = 1;i<s.size();++i){
    for(char x = 'a';x<='z' ;++x){
        if(s[i]==x) mini++;
    }
    }
    if(mini!=s.size()-2) {
        cout << "WA" <<endl;
        return 0;
    }
    cout << "AC" <<endl;
}