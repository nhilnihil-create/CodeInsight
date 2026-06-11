#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans = INT_MAX;
    for(int i = 0; i < s.length()-2; i++){
        int tmp = (s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
        //cout << tmp << " ";
        tmp = abs(753-tmp);
        //cout << tmp << endl;
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}