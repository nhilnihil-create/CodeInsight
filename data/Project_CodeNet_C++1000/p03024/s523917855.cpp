#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    cin >> s;

    int sum = 0;
    for(int i = 0 ; i < s.size(); i++) {
        if(s[i] == 'o') sum++;
    }

    if(8 - sum <= 15 - s.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
