#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

int main(){
    int n;
    cin >> n;
    P a[2*n], b[2*n];
    rep(i, n){
        cin >> a[i].first >> b[i].first;
        a[i].second = i;
        b[i].second = i;
    }
    rep(i, n) {
        cin >> a[n+i].first >> b[n+i].first;
        a[n+i].second = n + i;
        b[n+i].second = n + i;
    }
    sort(a, a + 2 * n);
    sort(b, b + 2 * n, greater<P>());
    // rep(i, 2 * n){
    //     cout << a[i].first << " " << a[i].second << endl;;
    // }
    // cout << endl;
    // rep(i, 2 * n){
    //     cout << b[i].first << " " << b[i].second << endl;;
    // }
    int ans = 0;
    int made[2*n];
    rep(i, 2 * n) made[i] = 0;
    rep(i, 2 * n){
        if (a[i].second >= n){
            bool flag = false;
            bool flag2 = false;
            for (int j = 0; j < 2 * n && !flag2; j++){
                if (b[j].second == a[i].second){
                    flag = true;
                }
                if (flag && b[j].second < n && made[b[j].second] == 0){
                    // cout << a[i].second << " " << b[j].second << endl;
                    for (int k = 0; k < i; k++){
                        // cout << a[k].second << endl;
                        if (a[k].second == b[j].second){
                            ans++;
                            made[a[i].second] = 1;
                            made[b[j].second] = 1;
                            flag2 = true;
                            break;
                        }
                    }
                }
            }
        }
        // rep(i, 2 * n) cout << made[i] << " ";
        // cout << endl;
    }
    // rep(i, 2 * n) cout << made[i] << " ";
    // cout << endl;
    cout << ans << endl;
}