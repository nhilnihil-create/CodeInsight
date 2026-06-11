#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:
wa:
反省:
考察:
*/
int main() {
    int a[4], b[4];
    int c[5] = {0};
    int c1 = 0, c2 = 0;
    for(int i = 0; i < 3; i++) {
        cin >> a[i] >> b[i];
        c[a[i]]++;
        c[b[i]]++;
    }
    for(int i = 1; i <= 4; i++){
        if(c[i] == 1) c1++;
        else if(c[i] == 2) c2++;
    }
    if(c1 == 2 && c2 == 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}