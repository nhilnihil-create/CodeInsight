#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,M,K,A;
    int cnt = 0;

    cin >> N >> M ;
    map<int,int> mp;
    for(int i=0;i<N;i++) {
        cin >> K;
        for(int j=0;j<K;j++) {
            cin >> A;
            mp[A]++;
        }
    }

    for(auto m:mp) {
        if(m.second == N){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
