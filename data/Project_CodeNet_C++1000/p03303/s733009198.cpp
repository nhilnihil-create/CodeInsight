#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;
    int i = 0;
    while(i <= s.size()-1){
        cout << s[i];
        i += n;
    }
    cout << endl;
    return 0;
}