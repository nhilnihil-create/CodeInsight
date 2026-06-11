#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    int h,w; cin >> h >> w;
    vector<vector<char>> v(h+2,vector<char> (w+2));
    for(int i=0;i<h+2;i++){
        for(int j=0;j<w+2;j++){
            if(i==0||i==h+1||j==0||j==w+1) v[i][j] = '.';
            else cin >> v[i+1][j+1];
        }
    }

    string ans = "Yes";
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(v[i][j] == '#'){
                if(v[i-1][j]=='.'&&v[i+1][j]=='.'&&v[i][j-1]=='.'&&v[i][j+1]=='.') ans = "No";
            }
        }
    }
    cout << ans << endl;
}
