#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    string s;
    cin >> s;
    bool fg1 = true;//yymm
    bool fg2 = true;//mmyy
    if(s[2] == '0' && s[3] == '0') fg1 = false;
    else if(s[2] != '0' && s[2] != '1') fg1 = false;
    else if(s[2] == '1' && s[3] == '3') fg1 = false;
    else if(s[2] == '1' && s[3] == '4') fg1 = false;
    else if(s[2] == '1' && s[3] == '5') fg1 = false;
    else if (s[2] == '1' && s[3] == '6') fg1 = false;
    else if(s[2] == '1' && s[3] == '7') fg1 = false;
    else if(s[2] == '1' && s[3] == '8') fg1 = false;
    else if(s[2] == '1' && s[3] == '9') fg1 = false;
    string t = s;
    s[0] = t[2];
    s[1] = t[3];
    s[2] = t[0];
    s[3] = t[1];
    if(s[2] == '0' && s[3] == '0') fg2 = false;
    else if(s[2] != '0' && s[2] != '1') fg2 = false;
    else if(s[2] == '1' && s[3] == '3') fg2 = false;
    else if(s[2] == '1' && s[3] == '4') fg2 = false;
    else if(s[2] == '1' && s[3] == '5') fg2 = false;
    else if (s[2] == '1' && s[3] == '6') fg2 = false;
    else if(s[2] == '1' && s[3] == '7') fg2 = false;
    else if(s[2] == '1' && s[3] == '8') fg2 = false;
    else if(s[2] == '1' && s[3] == '9') fg2 = false;

    if(fg1 && fg2) {
        cout << "AMBIGUOUS" << endl;
    } else if(fg1) cout << "YYMM" <<endl;
    else if (fg2) cout << "MMYY" << endl;
    else cout << "NA" << endl;


    
}