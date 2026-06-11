#include <bits/stdc++.h>
using namespace std;
bool isValid(char c){
    bool ret = false;
    switch(c){
        case 'A':
        case 'C':
        case 'G':
        case 'T':
            ret = true;
            break;
        default:
            break;
    }
    return ret;
}
int main(){
    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        if(isValid(s[i])){
            cnt++;
        }else{
            cnt = 0;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}