#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    int N, C;
    cin >> N >> C;
    vector<vector<pair<int,int>>> chan(C);
    rep(i, N){
        i64 s, t, c;
        cin >> s >> t >> c;
        s *= 2,t *= 2; c--;
        chan[c].emplace_back(make_pair(s,t));
    } 

    const int t_max = 2*100000+2;
    vector<int> time_table(t_max, 0);
    for(int c = 0; c < C; c++){
        vector<int> table(t_max, 0);
        for(auto& p : chan[c]){
            table[p.first - 1]++;
            table[p.second + 1]--;
        }
        for(int i = 1; i < t_max; i++) table[i] += table[i-1];
        for(int left = 0; left < t_max; left++){
            if(table[left] == 0) continue;

            int right = left;
            while(right < t_max && table[right] > 0) right++;
            time_table[left]++;
            time_table[right]--;
            left = right - 1;
        }
    }

    for(int i = 1; i < t_max; i++) time_table[i] += time_table[i-1];
    cout << *max_element(all(time_table)) << endl;
}