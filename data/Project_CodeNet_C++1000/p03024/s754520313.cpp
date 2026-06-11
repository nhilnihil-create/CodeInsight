#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string str;
    int cnt = 0;
    cin >> str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='x') cnt++;
    }
    if(cnt<=7)  cout << "YES\n";
    else    cout << "NO\n";
}