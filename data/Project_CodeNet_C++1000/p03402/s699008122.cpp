#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include<queue>

using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n; ++i)
#define ALL(a) (a).begin(),(a).end()
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)

#define MOD 1000000007
int main(){
    int a, b;
    cin >> a >> b;
    int n = 50;
    char g[2*n][2*n];
    rep(i, 2*n)rep(j, 2*n){
        if(i < n)g[i][j] = '#';
        else g[i][j] = '.';
    }
    int ca, cb;
    ca = cb = 0;
    rep(i, 2*n)rep(j, 2*n){
        if(i < n-1){
            if(i%2 == 0 && j%2 == 0 && ca < a-1)g[i][j] = '.', ca++;
        }
        else if (i > n){
            if(i%2 == 0 && j%2 == 0 && cb < b-1)g[i][j] = '#', cb++;
        }
    } 
    cout << 2*n << " " << 2*n << endl;
    rep(i,2*n){
        rep(j, 2*n)cout << g[i][j];cout << endl;
    }


}