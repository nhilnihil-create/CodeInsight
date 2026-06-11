#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans = "NO";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'k'){
            if(s.substr(i, 7) == "keyence"){
                ans = "YES";
            }
        }
    }

    for(int i = 1; i < 7; i++){
        if(s.substr(0, i)+s.substr(s.size()-(7-i)) == "keyence"){
            ans = "YES";
        }
    }
    cout << ans << endl;
    return 0;
}