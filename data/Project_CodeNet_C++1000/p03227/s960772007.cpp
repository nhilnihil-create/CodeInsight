#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >>s;
    if(s.size()==2) cout << s << endl;
    else {
        char tmp=s[0];
        s[0]=s[2];
        s[2]=tmp;
        cout << s << endl;
    }
}