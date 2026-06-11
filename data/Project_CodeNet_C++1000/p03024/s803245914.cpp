#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans=0 ;
    string s;
    cin >> s;
    for(int i;i<s.size();i++){
        if(s.at(i)=='x'){
            ans++;
        }
    }
    if(ans>=8){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}