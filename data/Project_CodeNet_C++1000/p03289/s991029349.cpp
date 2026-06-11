#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    string s;
    cin >> s;
    //cout << s.front() << endl;
    if(s.front() != 'A'){
        cout << "WA" << endl;
        return 0;
    }
    bool ok1 = false;
    bool ok2 = false;
    for(int i=2;i<s.size()-1;i++){
        if(s[i]=='C'){
            if(!ok1) ok1 = true;
            else ok2 = true;
        }
    }
    if(!ok1){
        cout << "WA" << endl;
        return 0;
    }
    if(ok2){
        cout << "WA" << endl;
        return 0;
    }
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(isupper(s[i])) cnt++;
    }
    //cout << cnt << endl;
    if(cnt == 2){
        cout << "AC" << endl;
    }else{
        cout << "WA" << endl;
    }
}