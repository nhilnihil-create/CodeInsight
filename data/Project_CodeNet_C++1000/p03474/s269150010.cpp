#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B;
    string s;
    bool check = true;
    cin >> A >> B >> s;
    for(int i=0;i<A;i++) {
        if(!isdigit(s[i])) check = false;
    }
    if(s[A] != '-') check = false;
    for(int i=A+1;i<(A+B);i++) {
        if(!isdigit(s[i])) check = false;
    }

    if(check) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
