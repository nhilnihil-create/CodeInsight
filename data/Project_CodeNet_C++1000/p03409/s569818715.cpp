#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    
    int N;
    cin >> N;
    set<pair<int, int>> AB;
    for (int i = 0; i < N; i++) {
        pair<int, int>p;
        cin >> p.first >> p.second;
        AB.insert(p);
    }
    
    set<pair<int, int>> CD;
    for (int i = 0; i < N; i++) {
        pair<int, int>p;
        cin >> p.first >> p.second;
        CD.insert(p);
    }

    int ans = 0;
    for (auto i : CD) {
        int sum1 = -1;
        int sum2 = -1;
        for (auto j : AB) {
            if (i.second > j.second && i.first > j.first) {
                if (sum2 < j.second) {
                    sum1 = j.first;
                    sum2 = j.second;
                }
            }
        }
        if (sum1 != -1 && sum2 != -1) {
            AB.erase(pair<int, int>(sum1, sum2));
            ans++;
        }
    }
    cout << ans << endl;
}