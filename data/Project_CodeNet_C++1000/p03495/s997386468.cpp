#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> balls(200000, 0);
    rep(i, N){
        int tmp;
        cin >> tmp;
        balls.at(tmp)++;
    }
    sort(balls.begin(), balls.end());
    
    int ans = 0;
    bool flag = true;

    int diff_num = 0;
    for(int ball : balls){
        if(ball) diff_num++;
    }
    if(diff_num > K){
        for(int i=0; i<balls.size(); i++){
            if(balls.at(i)){
                ans += balls.at(i);
                diff_num--;
                if(diff_num == K){
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}