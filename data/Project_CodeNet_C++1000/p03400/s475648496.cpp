#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, D, X;
    cin >> N >> D >> X;

    vector<int> A(N);
    for (int i=0; i<N; i++){
        cin >> A.at(i);
    }

    int cnt = 0, cnt_buf;
    for (auto x: A){
        cnt_buf = 0;

        while ((cnt_buf*x+1) <= D){
            cnt_buf++;
        }
        cnt += cnt_buf;
    }

    int ans;
    ans = cnt + X;

    cout << ans << endl;
    return 0;
}