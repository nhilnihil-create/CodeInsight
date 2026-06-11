#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    if (s.front() != '1' || s.back() != '0'){
        cout << - 1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++){
        if (s[i] != s[n - i - 2]){
            cout << - 1 << endl;
            return 0;
        }
    }
    int now = 1;
    for (int i = 0; i < n - 1; i++){
        cout << now << " " << i + 2 << endl;
        if (s[i] == '1') now = i + 2;
    }
}