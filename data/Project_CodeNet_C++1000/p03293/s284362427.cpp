#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s; cin >> t;

    bool flg = false;
    if(s == t) flg = true;
    else{
        for(int i=1; i<s.length(); i++){
            s = s.at(s.length()-1) + s.substr(0, s.length()-1);
            if(s == t){
                flg = true; break;
            }
        }  
    }
    if(flg) cout << "Yes" << endl;
    else    cout << "No" << endl;

    return 0;

}