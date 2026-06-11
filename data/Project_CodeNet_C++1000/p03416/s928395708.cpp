/**
    BISMILLAH
    @Author : Arham
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int count = false;
    string s;
    for(int i = a; i <= b; i++) {
        int temp = i, c = true;
        int val = 0;
        while(temp) {
            int r = temp % 10;
            temp /= 10;
            s[val] = r + '0';
            val++;
        }
        for(int j = 0, k = val - 1; j < val / 2; j++, k--) {
            if(s[j] != s[k]) {
                c = false;
                break;
            }
        }
        if(c)
            count++;
    }
    cout << count << endl;

    return 0;
}