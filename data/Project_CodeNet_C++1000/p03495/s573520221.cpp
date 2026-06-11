#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    map<int, int> mp;
    
    cin >> N >> K;
    int a[N];
    for (int i = 0; i < N; i++){
        cin >> a[i];
        mp[a[i]] += 1;
    }
    

    int type_num = 0;
    for (auto p : mp) {
        ++type_num;
    }

    int num[type_num] = {0};
    int count = 0;
    for (auto p : mp) {
        auto value = p.second;
        num[count] += value;
        count++;
    }

    int res = 0;
    sort(num, num + count);
    for (int i = 0; i < type_num - K; i++){
        res += num[i];
    }
    cout << res << endl;
}