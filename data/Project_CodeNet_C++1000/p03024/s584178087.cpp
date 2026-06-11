#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            cnt++;
        }
    }
    if(cnt + 15 - n >= 8){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}