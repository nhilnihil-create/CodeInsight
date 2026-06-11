#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt_a = 0;
    int cnt_b = 0;
    int cnt_c = 0;
    for (char x: s) {
        
        if (x == 'a') {
            cnt_a++;
        }else if (x == 'b'){
            cnt_b++;
        }else if (x == 'c') {
            cnt_c++;
        }
    }
    if (cnt_a == 1 && cnt_b == 1 && cnt_c == 1) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    
}