#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int func(int time, int f){
    int val;
    for(int i = time; i <= time+f; i++){
        if(i % f == 0){
            val = i;
            break;
        }
    }
    return val;
}

int main(){
    int N;
    cin >> N;
    vector<int> c(N, 0), s(N, 0), f(N, 0);
    rep(i, N-1){
        cin >> c[i] >> s[i] >> f[i];
    }

    //iを出発駅としたときの、N駅にたどり着くための時間
    vector<int> time(N, 0);
    rep(i, N-1){
        for(int j = i; j < N-1; j++){
            if(j == i) time[i] = s[j];
            else{
                time[i] = max(s[j], func(time[i], f[j]));
            }
            time[i] += c[j];
        }
    }
    rep(i, N) cout << time[i] << endl;
    return 0;
}