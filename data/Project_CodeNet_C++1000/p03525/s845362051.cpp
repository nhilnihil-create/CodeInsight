#include <bits/stdc++.h>
using namespace std;

int cnt[15];
vector<int> times = {0};

int helper(int hour){

    if(hour == 13){

        int low = 30;

        for(int i = 0; i < times.size(); ++i){
            for(int j = i + 1; j < times.size(); ++j){
                int d = abs(times[i] - times[j]);
                low = min(low, min(d, 24 - d));
            }
        }

        return low;

    }

    if(cnt[hour] == 0) return helper(hour + 1);


    for(int i = 0; i < cnt[hour]; ++i)
        times.push_back((i & 1) == 0 ? 24 - hour : hour);

    int best = helper(hour + 1);

    for(int i = 0; i < cnt[hour]; ++i) times.pop_back();
    for(int i = 0; i < cnt[hour]; ++i)
        times.push_back((i & 1) == 1 ? 24 - hour : hour);

    best = max(best, helper(hour + 1));

    for(int i = 0; i < cnt[hour]; ++i) times.pop_back();

    return best;

}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; ++i){
        int j; cin >> j; ++cnt[j];
    }

    cout << helper(0);

    return 0;

}
