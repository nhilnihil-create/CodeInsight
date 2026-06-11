/*
      author : nishi5451
      created: 11.08.2020 01:18:06
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    if(s[0]==s[1] && s[1]==s[2]) cout  << "Yes" << endl; 
    else if(s[1]==s[2] && s[2]==s[3]) cout  << "Yes" << endl; 
    else cout << "No" << endl;
    return 0;
}