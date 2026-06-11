#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;

string s;
int solve(){
    int l = s.size();
    int ans = INF;
    for(int i=0;i<l-1;i++){
        if(s[i]==s[i+1])continue;
        chmin(ans,max(i+1,l-i-1));
    }
    if(ans==INF)return l;
    return ans;
}

int main(){
    cin >> s;
    cout << solve() << endl;
    return 0;
}
