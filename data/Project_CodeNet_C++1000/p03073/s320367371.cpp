#include <bits/stdc++.h>
using  namespace std;

int main(){

    string s;
    cin >> s;

    int size = s.size();
    int ans = 0;
    char temp = s.at(0);
    for (int i=1; i<size; i++){
        if (temp == s.at(i)){
            ans++;

            if (s.at(i) == '0') s.at(i) = '1';
            else s.at(i) = '0'; 
        }
        temp = s.at(i);
    }

    cout << ans << endl;
    return 0;
}