#include <bits/stdc++.h>
using namespace std;
int main(){
    string m;
    cin >> m;
    int s1,s2,s3;
    s1 = int(m[0]) - 48;
    s2 = int(m[1]) - 48;
    s3 = int(m[2]) - 48;
    cout << s1 + s2 + s3 << endl;
}