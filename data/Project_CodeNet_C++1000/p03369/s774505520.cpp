#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    int ans = 700;
    for(int i = 0; i < s.size(); i++) if(s[i] == 'o') ans += 100;
    cout << ans << endl;    
    return 0;
}