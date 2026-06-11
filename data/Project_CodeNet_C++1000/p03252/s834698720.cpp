#include <iostream>
#include <string>
using namespace std;

int main(){
    string s, t;
    cin >> s;
    cin >> t;

    char memo[26] = {};
    char memo1[26] = {};
    string ans = "Yes";
    for(int i = 0; i < s.length(); i++){
        if(memo[t[i]-'a'] == 0){
            memo[t[i]-'a'] = s[i];
        }else if(memo[t[i]-'a'] != s[i]){
            ans = "No";
        }
        if(memo1[s[i]-'a'] == 0){
            memo1[s[i]-'a'] = t[i];
        }else if(memo1[s[i]-'a'] != t[i]){
            ans = "No";
        }
    }
    
    cout << ans << endl;
    return 0;
}