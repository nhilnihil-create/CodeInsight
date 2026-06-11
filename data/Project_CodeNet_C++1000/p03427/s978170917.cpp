#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int ans = (s[0] - '0') + 9 * (int)(s.size()-1);
    for(int i = 1; i < s.size(); i++){
        if(s[i] != '9'){
            ans--;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}