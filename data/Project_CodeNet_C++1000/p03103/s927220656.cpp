#include <bits/stdc++.h>
using namespace std;

using P = pair<int64_t,int64_t>;
int main(void) {
    int64_t N,M;
    int64_t money = 0;
    cin >> N >> M;
    vector<P> ab(N);
    for(int i=0;i<N;i++) {
        cin >> ab[i].first >> ab[i].second;
    }

    sort(ab.begin(), ab.end());
    for(int i=0;M;i++) {
        if(ab[i].second <= M) {
            //全部買う
            money += (ab[i].first * ab[i].second);
            M -= ab[i].second;
        } else {
            //残りだけ買う
            money += (ab[i].first * M);
            M =0;
        }        
    }

    cout  << money << endl;
    return 0;
}
