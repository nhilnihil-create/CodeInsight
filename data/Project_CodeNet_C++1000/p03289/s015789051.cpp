#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool check=false;
//    if('a'<=s.at(0)) cout << 1 << endl;

    for(int i=2; i<s.size()-1; i++){
        if('a'<=s.at(i) && s.at(i)<='z'){
        }
        else if(s.at(i)=='C'){
            if(check==false){
                check=true;
            }
            else if(check==true){
                check=false;
                break;
            }
        }
        else break;
    }
    if(s.at(0)!='A') check=false;
    if('a'>s.at(1) || s.at(1)>'z') check=false;
    if('a'>s.at(s.size()-1) || s.at(s.size()-1)>'z') check=false;

    if(check==true) cout << "AC" << endl;
    else cout << "WA" << endl;
}