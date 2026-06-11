#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int A,B;
    cin >> A >> B;
    string S;
    cin >> S;
    
    string str1, str2;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '-') {
            str2 = S.substr(i+1, S.size());
            break;
        }
        str1 += S[i];
    }
    
    if (A != str1.size() || B != str2.size()) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < str1.size(); i++) {
        if (!('0' <= str1[i] && str1[i] <= '9')){
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i < str2.size(); i++) {
        if (!('0' <= str2[i] && str2[i] <= '9')){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
}
