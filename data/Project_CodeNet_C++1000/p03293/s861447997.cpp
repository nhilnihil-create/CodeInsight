#include <bits/stdc++.h>
using namespace std;
string rotate(string s){
    string ret;
    ret += s.back();
    for(int i = 0; i < s.length()-1; i++){
        ret += s[i];
    }
    return ret;
}
int main(){
    string s,t;
    cin >> s >> t;
    if(s.compare(t)==0){
        cout << "Yes" << endl;
        return 0;
    }
    int cnt = 0;
    while(true){
        s = rotate(s);
        if(s.compare(t)==0){
            cout << "Yes" << endl;
            return 0;
        }
        cnt++;
        if(cnt>=s.length())break;
    }
    cout << "No" << endl;
    return 0;
}