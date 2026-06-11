#include<bits/stdc++.h>

int main(){
    using namespace std;
    string s;
    cin >> s;
    puts(count(s.begin(), s.end(), 'x') > 7 ? "NO" : "YES");
    return 0;
}