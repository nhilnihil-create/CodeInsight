#include<bits/stdc++.h>
using namespace std;
#define ll long long

int N;
vector<int> x[29][2];
ll cnt[29];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        for(int j = 0; j <= 28; j++){
            int mask = (2 << j) - 1;
            x[j][(A >> j) & 1].push_back(mask & A);
        }
    }
    for(int i = 0; i <= 28; i++){
        for(int j = 0; j < 2; j++){
            sort(x[i][j].begin(), x[i][j].end());
        }
    }
    for(int i = 0; i < N; i++){
        int B;
        cin >> B;
        for(int j = 28; j >= 0; j--){
            B = B & ((2 << j) - 1);
            if((1 << j) <= B){
                int ub = x[j][1].size();                
                int lb = (3 << j) - B;
                lb = lower_bound(x[j][1].begin(), x[j][1].end(), lb) - x[j][1].begin();
                cnt[j] += ub - lb;

                ub = (2 << j) - 1 - B;
                ub = upper_bound(x[j][0].begin(), x[j][0].end(), ub) - x[j][0].begin();
                lb = 0;
                cnt[j] += ub - lb;
            }else{
                int ub = (2 << j) - 1 - B;
                ub = upper_bound(x[j][1].begin(), x[j][1].end(), ub) - x[j][1].begin();
                int lb = 0;
                cnt[j] += ub - lb;

                ub = x[j][0].size();
                lb = (1 << j) - B;
                lb = lower_bound(x[j][0].begin(), x[j][0].end(), lb) - x[j][0].begin();
                cnt[j] += ub - lb;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 29; i++){
        if(cnt[i] & 1ll) ans |= 1 << i;
    }
    cout << ans << endl;
    return 0;
}
