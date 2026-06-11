#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'a') a++;
        else if(s[i] == 'b')    b++;
        else c++; 
    }
    int m = min(a, b);
    m = min(m, c);
    a -= m;
    b -= m;
    c -= m;
    if(a <= 1 && b <= 1 && c <= 1)  cout << "YES";
    else    cout << "NO" << endl;
}