#include <bits/stdc++.h>
using namespace std;

int main(){
    string c1,c2;
    cin >> c1 >> c2;
    bool flag = false;
    if (c1[0] == c2[2] && c1[1] == c2[1] && c1[2] == c2[0]){
        flag = true;
    }
    cout << (flag ? "YES" : "NO") << endl;
}