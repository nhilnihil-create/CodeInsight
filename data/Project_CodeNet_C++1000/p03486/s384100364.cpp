#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, t, ans;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    int i = 0;
    while(i < s.size()){
        if(s[i]-'a'==t[i]-'a'){
            if(i == s.size()-1 && s.size() < t.size()) ans = "Yes";
            else if(i == s.size()-1 && s.size() >= t.size()) ans = "No";
            ++i;
        }
        else if(s[i]-'a'<t[i]-'a'){
            ans = "Yes";
            break;
        }
        else{
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}