#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string a;
    cin >> a;
    int cnt = 0;
    if ('o' == a[0]) cnt++;
    if ('o' == a[1]) cnt++;
    if ('o' == a[2]) cnt++;

    cout << 700 + (cnt * 100) << endl;

    return 0;
}