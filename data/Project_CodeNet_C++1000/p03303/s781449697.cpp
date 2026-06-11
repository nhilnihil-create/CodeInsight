#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int w,i=0;
    cin >> w;
    while (i*w < s.length()) {
        cout << s[w * i];
        i++;
    }
    cout << endl;
    return 0;
}