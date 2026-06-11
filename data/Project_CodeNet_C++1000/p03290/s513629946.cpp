#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    int d,g; cin >> d >> g;
    vector<pair<int,int>> p(d);
    long ans = 0;
    for(int i=0; i<d; i++){
        cin >> p[i].first >> p[i].second;
        ans += p[i].first;
    }

    for(int bit=0; bit<(1<<d); bit++){
        long tmp = 0;
        long score = 0;
        for(int i=0; i<d; i++){
            if(bit & (1<<i)){
                tmp += p[i].first;
                score += (i+1) * 100 * p[i].first + p[i].second;
            }
        }

        if(score < g){
            for(int i=d-1; i>=0; i--){
                if(!(bit & (1<<i)) && (i+1) * p[i].first * 100 >= g - score ){
                    tmp += (g-score-1) / ((i+1) * 100) + 1;
                    score += ((g-score-1) / ((i+1) * 100) + 1) * (i+1)*100; 
                    break;
                }
            }
        }
        if(score >= g && tmp < ans){
            ans = tmp;
        }
    }
    cout << ans << endl;
}