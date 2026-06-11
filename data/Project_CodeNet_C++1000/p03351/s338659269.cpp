#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string  s = "Yes";
    if(min(abs(a-b), abs(a-c)) > d || min(abs(c-a), abs(c-b)) > d){
        s = "No";
    }
    cout << s << endl;
    return 0;
}