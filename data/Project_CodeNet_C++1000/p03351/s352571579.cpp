#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string ans="No";
    if ((abs(a-c) <= d) || ((abs(a-b) <= d) && (abs(b-c) <= d))) ans = "Yes";
    cout << ans << endl;
    return 0;
}