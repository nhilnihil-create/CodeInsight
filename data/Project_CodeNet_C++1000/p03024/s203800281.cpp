#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    int n = 0;
    cin >> s;
    for(int i = 0;i < s.size();i++)if(s[i] == 'x')n++;
    if(n >= 8)cout << "NO";
    else cout << "YES";
}