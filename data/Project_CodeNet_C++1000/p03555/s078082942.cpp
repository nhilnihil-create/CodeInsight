#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s,v;
    cin >> s >> v;
    if(s.at(0) == v.at(2) && s.at(1) == v.at(1) && s.at(2) == v.at(0)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

}