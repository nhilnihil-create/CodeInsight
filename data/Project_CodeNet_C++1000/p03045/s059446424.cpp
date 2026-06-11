#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

int n, m, ans = 0;
bool flg[100100];
vi a[100100];
void nya(int n){
    flg[n] = true;
    for(int i : a[n]){
        if(!flg[i])
        nya(i);
    }
    return;
}
int main(){
    cin >> n >> m;
    rep(i, m){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    rep(i, n){
        if(!flg[i]){
            nya(i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}