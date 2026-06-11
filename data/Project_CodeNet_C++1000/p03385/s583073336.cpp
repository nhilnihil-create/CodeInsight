#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int a = count(s.begin(),s.end(),'a');
    int b = count(s.begin(),s.end(),'b');
    int c = count(s.begin(),s.end(),'c');

    a==1&&b==1&c==1?cout<<"Yes":cout<<"No";
    return 0;
}