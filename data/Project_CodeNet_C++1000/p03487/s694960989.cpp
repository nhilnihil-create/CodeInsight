#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,a;
    int cnt = 0;
    cin >> N;
    map<int,int> mp;
    for(int i=0;i<N;i++) {
        cin >> a;
        mp[a]++;
    }

    for(auto m:mp) {
        if(m.second > m.first) {
            cnt += m.second - m.first;
        } else if(m.second < m.first) {
            cnt += m.second;
        }
    }

    cout << cnt << endl;
    return 0;
}
