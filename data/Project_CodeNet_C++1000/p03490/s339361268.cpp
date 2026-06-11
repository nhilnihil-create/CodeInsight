#include<bits/stdc++.h>
using namespace std;

const int MAX_L = 8000;
int dp[MAX_L+1];
string s;

int main(){
    int x, y; cin >> s >> x >> y;

    vector<int> xx, yy;
    int cnt = 0, tmp = 0, sx = 0, sy = 0;

    for(auto c : s){
        if(c=='F') tmp++;
        else{
            if(cnt%2){
                yy.push_back(tmp); sy += tmp;
            }
            else{
                xx.push_back(tmp); sx += tmp;
            }
            tmp = 0; cnt++;
        }
    }

    if(tmp != 0){
        if(cnt % 2){
            yy.push_back(tmp); sy += tmp;
        }
        else{
            xx.push_back(tmp); sx += tmp;
        }
    }

    x -= xx[0]; sx -= xx[0];

    dp[0] = 1;
    for(int i=1;i<xx.size();i++){
        for(int j=1;j<=sx;j++){
            if(!dp[j] && xx[i]<=j) dp[j] = dp[j-xx[i]];
        }
    }

    if(abs(sx) < abs(x) || abs(sx%2) != abs(x%2) || !dp[(sx+x)/2]){
        cout << "No" << endl;
        return 0;
    }

    for(int i=1;i<=sy;i++) dp[i] = 0;
    for(int i=0;i<yy.size();i++){
        for(int j=1;j<=sy;j++){
            if(!dp[j] && yy[i]<=j) dp[j] = dp[j-yy[i]];
        }
    }

    if(abs(sy) < abs(y) || abs(sy%2) != abs(y%2) || !dp[(sy+y)/2]) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}