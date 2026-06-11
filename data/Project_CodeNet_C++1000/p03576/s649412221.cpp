#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 51;
int mp[MAX_N][MAX_N];
ll X[MAX_N], Y[MAX_N];
pair<ll, ll> dot[MAX_N];
int N, K;

int minmp(int i, int j) {
    if(i >= 0 && j >= 0) return mp[i][j];
    else return 0;
}

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> dot[i].first >> dot[i].second;
        X[i] = dot[i].first, Y[i] = dot[i].second;
    }
    
    sort(X, X + N);
    sort(Y, Y + N);

    /*
    for(int i = 0; i < N; ++i) {
        cout << X[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; ++i) {
        cout << Y[i] << " ";
    }
    cout << endl;
    */

    for(int i = 0; i < N; ++i) {
        int nx = lower_bound(X, X + N, dot[i].first) - X;
        int ny = lower_bound(Y, Y + N, dot[i].second) - Y;
        ++mp[nx][ny];
    }

    /*
    cout << endl;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    */

    //2次元累積和
    
    for(int i = 0; i < N; ++i) {
        for(int j = 1; j < N; ++j) 
            mp[i][j] += mp[i][j-1];
    }
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < N; ++j) 
            mp[i][j] += mp[i-1][j];
    }
    
    /*
    cout << endl;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    */

    ll res = LLONG_MAX;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = i + 1; k < N; ++k) {
                for(int l = j + 1; l < N; ++l) {
                    //累積和の取り方か、使い方がミスっていたらしい...
                    // num = の式に;が余分に入っていたらしい...
                    int num = minmp(k, l) - minmp(i-1, l)- minmp(k, j-1) + minmp(i-1, j-1);
                    
                    if(num >= K) {
                        /*
                        cout << i << " " << j << endl;
                        cout << k << " " << l << endl;
                        cout << endl;
                        */
                        ll S = 1LL * (X[k] - X[i]) * (Y[l] - Y[j]);
                        res = min(res, S);
                    }
                    
                    /*これだとAC
                    int num = 0;
                    ll lx = X[i], rx = X[k];
                    ll by = Y[j], uy = Y[l];
                    
                    for(int m = 0; m < N; ++m) {
                        if(lx <= dot[m].first && dot[m].first <= rx
                            && by <= dot[m].second && dot[m].second <= uy)
                                ++num;
                    }
                    if(num >= K) res = min(res, (rx - lx)*(uy - by));
                    */
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}