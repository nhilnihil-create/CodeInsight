#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    string s;
    int k;
    cin >> n >> k >> s;
    if(s[k-1] == 'A') s[k-1] = 'a';
    else if(s[k-1] == 'A') s[k-1] = 'a';
    else if(s[k-1] == 'B') s[k-1] = 'b';
    else if(s[k-1] == 'C') s[k-1] = 'c';
    else if(s[k-1] == 'D') s[k-1] = 'd';
    else if(s[k-1] == 'E') s[k-1] = 'e';
    else if(s[k-1] == 'F') s[k-1] = 'f';
    else if(s[k-1] == 'G') s[k-1] = 'g';
    else if(s[k-1] == 'H') s[k-1] = 'h';
    else if(s[k-1] == 'I') s[k-1] = 'i';
    else if(s[k-1] == 'J') s[k-1] = 'j';
    else if(s[k-1] == 'K') s[k-1] = 'k';
    else if(s[k-1] == 'L') s[k-1] = 'l';
    else if(s[k-1] == 'M') s[k-1] = 'm';
    else if(s[k-1] == 'N') s[k-1] = 'n';
    else if(s[k-1] == 'O') s[k-1] = 'o';
    else if(s[k-1] == 'P') s[k-1] = 'p';
    else if(s[k-1] == 'Q') s[k-1] = 'q';
    else if(s[k-1] == 'R') s[k-1] = 'r';
    else if(s[k-1] == 'S') s[k-1] = 's';
    else if(s[k-1] == 'T') s[k-1] = 't';
    else if(s[k-1] == 'U') s[k-1] = 'u';
    else if(s[k-1] == 'V') s[k-1] = 'v';
    else if(s[k-1] == 'W') s[k-1] = 'w';
    else if(s[k-1] == 'X') s[k-1] = 'x';
    else if(s[k-1] == 'Y') s[k-1] = 'y';
    else if(s[k-1] == 'Z') s[k-1] = 'z';
    cout << s << endl;
}