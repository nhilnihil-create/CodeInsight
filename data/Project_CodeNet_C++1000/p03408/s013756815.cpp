#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<string> str;
    vector<int> cnt;
    int n, m;
    string tmp;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tmp;
        auto itr = find(str.begin(), str.end(), tmp);
        if (itr == str.end()){
            str.emplace_back(tmp);
            cnt.emplace_back(1);
        } else{
            int index = distance(str.begin(), itr);
            cnt[index]++;
        }
    }
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> tmp;
        auto itr = find(str.begin(), str.end(), tmp);
        if (itr == str.end()){
            str.emplace_back(tmp);
            cnt.emplace_back(-1);
        } else{
            int index = distance(str.begin(), itr);
            cnt[index]--;
        }
    }
    int ans = 0;
    for (auto x : cnt){
        ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}