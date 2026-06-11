#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
typedef long long ll;

vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];
int main() {
    
    vector<vector<int>>c(3,vector<int>(3));
    rep(i,0,3){
        rep(j,0,3){
            cin>>c[i][j];
        }
    }
    vector<int>tmp(3);
    rep(i, 0, 2){
        tmp[0] = c[i+1][0] - c[i][0];
        tmp[1] = c[i+1][1] - c[i][1];
        tmp[2] = c[i+1][2] - c[i][2];
        if( tmp[0] != tmp[1] || tmp[0]!=tmp[2] || tmp[1]!=tmp[2] ){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
