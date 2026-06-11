#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++){
        if((s[i] - '0') != 9){
            goto skip;
        }
    }
    cout << (s[0] - '0') + 9 * (s.size() - 1) << endl;
    return 0;
    skip:
        cout << (s[0] - '0') + 9 * (s.size() - 1) - 1 << endl;
        return 0;
}