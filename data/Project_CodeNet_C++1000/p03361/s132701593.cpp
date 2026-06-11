#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>>s(55,vector<char>(55));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> s[i][j];
        }
    }
    bool judge = true;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'&&s[i+1][j]!='#'&&s[i-1][j]!='#'&&s[i][j-1]!='#'&&s[i][j+1]!='#') judge=false;
        }
    }
    if(judge) cout << "Yes" << endl;
    else cout << "No" << endl;
}