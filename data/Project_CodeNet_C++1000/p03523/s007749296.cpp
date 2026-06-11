#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, j = 0;
    string s, t = "AKIHABARA";
    cin >> s;
    s += " ";
    for(i=0; i<9; i++){
        if(s[j] == t[i]){
            j++;
        }else if(t[i] != 'A'){
            cout << "NO";
            return 0;
        }
    }
    if(s.length()-1 == j){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}