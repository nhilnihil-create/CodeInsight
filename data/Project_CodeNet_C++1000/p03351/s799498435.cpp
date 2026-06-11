#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;


int main () {
    int  a, b, c, d;
    cin >> a>> b >> c >> d;

    if(abs(a-c) <= d) cout << "Yes" << endl;
    else if (abs(a-b) <= d && abs(b-c) <=d) cout << "Yes" << endl;
    else cout << "No" << endl;



}