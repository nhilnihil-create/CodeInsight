#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(string s){
    int c1 = 0,c2 = 0;
    char num1 = '0' ,num2 = '1';
    for(int i=0;i<s.size();i++){
        if(s.at(i) != num1) c1++;
        if(num1 == '0'){
            num1 = '1';
        }else{
            num1 = '0';
        }
    }

    for(int i=0;i<s.size();i++){
        if(s.at(i) != num2) c2++;
        if(num2 == '0'){
            num2 = '1';
        }else{
            num2 = '0';
        }
    }

    cout << min(c1,c2) << endl;
}

int main(){
    string s;
    cin >> s;
    solve(s);
}