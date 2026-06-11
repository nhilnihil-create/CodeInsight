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
    string month = "";
    if((s[5] == '0' && s[6] == '1') || (s[5]=='0' && s[6] == '2') || (s[5] == '0' && s[6] == '3') || (s[5]=='0' && s[6] == '4')){
        cout << "Heisei" << endl;
        return 0;
    }  else {
        cout << "TBD"<< endl;
    }
   

}