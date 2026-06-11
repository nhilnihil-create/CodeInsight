#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int B = 31;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;

int x[N], y[N], p[N];

bool check(int xx, int yy, int pp){
    return (abs(xx) + abs(yy) <= p[pp+1]-1);
}
 
signed main() {
    IOS;
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;  cin >> n;
    int sum = -1;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        int p = abs((x[i] + y[i]) % 2);
        if(sum == -1)
            sum = p;
        else if(sum != p)
            return cout << -1, 0;
    }
    if(sum == 0){
        cout << B+1 << endl;
        cout << 1 << " ";
    }
    else
        cout << B << endl;
    p[0] = 1;
    cout << 1 << " ";
    for(int i = 1; i < B; i++){
        p[i] = (p[i-1] << 1);   
        cout << p[i] << " "; 
    }
    p[B] = p[B-1] << 1;
    cout << endl;
    for(int i = 1; i <= n; i++){
        vector<char> s(B, 'c');
        if(sum == 0){
            if(check(x[i] - 1, y[i], B-1)){
                x[i] -= 1;
                cout << 'R';
            }
            else if(check(x[i] + 1, y[i], B-1)){
                x[i] += 1;
                cout << 'L';
            }
            else if(check(x[i], y[i] - 1, B-1)){
                y[i] -= 1;
                cout << 'U';
            }
            else if(check(x[i], y[i] + 1, B-1)){
                y[i] += 1;
                cout << 'D';
            }
        }
        //cout << x[i] << " " << y[i] << endl;
        for(int b = B-1; b >= 0; b--){
            if(check(x[i] - p[b], y[i], b-1)){
                x[i] -= p[b];
                s[b] = 'R';
            }
            else if(check(x[i] + p[b], y[i], b-1)){
                x[i] += p[b];
                s[b] = 'L';
            }
            else if(check(x[i], y[i] - p[b], b-1)){
                y[i] -= p[b];
                s[b] = 'U';
            }
            else if(check(x[i], y[i] + p[b], b-1)){
                y[i] += p[b];
                s[b] = 'D';
            }
            //cout << x[i] << " " << y[i] << endl;
        }
        for(int b = 0; b <= B-1; b++)
            cout << s[b];
        cout << endl;
    }
    return 0;
}