#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,Q;
    int cnt;
    string S;
    int times;
    
    cin >> N >> Q >> S;

    vector<pair<int,int>> lr(Q);
    for(int i=0;i<Q;i++) {
        cin >> lr[i].first >> lr[i].second;
    }

    cnt = 0;
    vector<int> sum(N,0);
    for(int i=0;i<(N-1);i++) {
        sum[i] = cnt;
        if(S[i] == 'A' && S[i+1] == 'C') {
            cnt++;
            sum[i] = cnt;
        }
    }

    for(int i=0;i<Q;i++) {
        times = sum[lr[i].second-2] - sum[lr[i].first-2];
        if(times < 0) times = 0;
        cout << times << endl;
    }

    return 0;
}
