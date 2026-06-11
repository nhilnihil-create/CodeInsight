#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    map<char,int>hexmp;

    hexmp['A'] = 10;
    hexmp['B'] = 11;
    hexmp['C'] = 12;
    hexmp['D'] = 13;
    hexmp['E'] = 14;
    hexmp['F'] = 15;
    char A,B;
    cin >> A >> B;

    if(hexmp[A] > hexmp[B])cout << ">" << endl;
    else if (hexmp[A] == hexmp[B])cout << "=" << endl;
    else cout << "<" << endl; 
}  