#include <iostream>
#include <string>
using namespace std;
int main(){
    int a; cin >> a;
    string s; cin >> s;
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        string a = s.substr(0,i);
        string b = s.substr(i);
        int cnt = 0;
        for(char c = 'a'; c <= 'z'; c++){
            bool flag1 = false, flag2 = false;
            for(char m:a) if(m == c) flag1 = true;
            for(char m:b) if(m == c) flag2 = true;
            if(flag1&&flag2) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
//Saw the solution video
