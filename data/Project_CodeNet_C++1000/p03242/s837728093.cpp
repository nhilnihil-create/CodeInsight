#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    string o;
    for(auto x:s){
        o+='9'-(x-'0')+1;
    }
    cout << o;
}