#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, C;
    cin >> n >> C;

    vector<pair<int, pair<int, int>>> program(n);// (c, (s,t))
    for(int i=0; i<n; i++){
        cin >> program[i].second.first 
            >> program[i].second.second 
            >> program[i].first;
    }
    sort(program.begin(),program.end());

    vector<int> rec(2000010);
    int s = program[0].second.first;
    int t = program[0].second.second;
    for(int i=0; i<n; i++){
        if(i < n - 1 
        && program[i].first         == program[i+1].first
        && program[i].second.second == program[i+1].second.first){
            t = program[i+1].second.second;
        }
        else{
            //cout << s << " " << t << endl;
            rec[2 * s - 1] += 1;
            rec[2 * t]     -= 1;

            if(i < n - 1){
                s = program[i+1].second.first;
                t = program[i+1].second.second;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<200010; i++){
        rec[i] += rec[i-1];
        ans = max(ans, rec[i]);
    }
    //for(int i=0; i<100; i++) cout << i << " : " << rec[i] << endl;
    cout << ans << endl;
    return 0;
}