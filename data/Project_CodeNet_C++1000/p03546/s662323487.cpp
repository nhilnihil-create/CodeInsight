#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int h,w;
    cin >> h >> w;
    int cost[10][10];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> cost[i][j];
        }
    }
    int cnt[10]={};
    for(int i = 0; i < h*w; i++) {
        int tmp;
        cin >> tmp;
        if(tmp==-1) continue;
        else cnt[tmp]++;
    }

    for(int k = 0; k < 10; k++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cost[i][j] = min(cost[i][j],(cost[i][k]+cost[k][j]));
            }
        }
    }

    int ans=0;
    for(int i = 0; i < 10; i++) {
        ans+=cnt[i]*cost[i][1];
    }

    cout << ans << "\n";
    return 0;
}