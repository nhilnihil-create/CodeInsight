#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                if(i-1 >= 0 && j-1 >= 0)a[i-1][j-1]++;
                if(i-1 >= 0)a[i-1][j]++;
                if(i-1 >= 0 && j+1 < w)a[i-1][j+1]++;
                if(j-1 >= 0)a[i][j-1]++;
                if(j+1 < w)a[i][j+1]++;
                if(i+1 < h && j-1 >= 0)a[i+1][j-1]++;
                if(i+1 < h)a[i+1][j]++;
                if(i+1 < h && j+1 < w)a[i+1][j+1]++;
            }
        }   
    }

    rep(i,h){
        rep(j,w){
            if(s[i][j] != '#')cout << a[i][j];
            else cout << '#';
        }
        cout << endl;
    }
    return 0;
}