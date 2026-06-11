#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    int h, w;
    cin >> h >> w;
    vector<vector<char>> v(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> v[i][j];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(v[i][j] == '#'){
                bool ok = false;
                for(int dx = -1; dx <= 1; dx+=2){
                    if(j+dx < 0 || j+dx >= w) continue;
                    if(v[i][j+dx] == '#') ok = true;
                }
                
                for(int dy = -1; dy <= 1; dy+=2){
                    if(i+dy < 0 || i+dy >= h) continue;
                    if(v[i+dy][j] == '#') ok = true;
                }                
                if(!ok){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
