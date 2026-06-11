#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long int ans = 0;
    int bnum = 0;
    for(int i = 0; i+1 < s.length(); i++){
        if(s[i] == 'B') bnum++;
        if(s[i] == 'B' && s[i+1] == 'W'){
            ans += bnum;
            s[i+1] = 'B';
            bnum--;
        }
    }
    cout << ans << endl;
    return 0;
}