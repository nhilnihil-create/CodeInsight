#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int allE = 0;int allW = 0;
    for(int i = 0;i<s.size();i++) {
        if(s[i] == 'E') allE++;
        else allW++;
    }
    int ans = s.size();
    int curE = 0;int curW = 0;
    for(int i = 0;i<s.size();i++) {
        if(s[i] == 'E') allE--;
        ans = min(ans,allE+curW);
        if(s[i] == 'W') curW++;
    }
    cout << ans << endl;
}