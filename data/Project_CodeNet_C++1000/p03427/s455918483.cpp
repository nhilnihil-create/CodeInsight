#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool check = true;
    for(int i = 1; i < n; i++){
        if(s[i] != '9'){
            check = false;
            break;
        }
    }
    if(check){
        cout << s[0]-'0' + 9*(n-1) << endl;
    }else{
        cout << s[0]-'1' + 9*(n-1) << endl;
    }
    return 0;
}
