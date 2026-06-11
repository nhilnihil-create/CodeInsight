#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    if (A*B < N || A+B >= N+2) {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    vector<int> ans(N, 0);
    while (true) {
        if (N - (cnt+1)*B + (cnt+1) > A){
            for (int i = 0; i < B; i++) {
                ans[i+cnt*B] = cnt*B+B-i;
            }
            cnt++;
        }else{
            int t = ((N-cnt*B)+cnt)-A+1;
            for (int i = 0; i < t; i++) {
                ans[i+cnt*B] = cnt*B+t-i;
            }
            for (int i = cnt*B+t; i < N; i++) ans[i] = i+1;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (i < N-1) printf("%d ", ans[i]);
        else printf("%d\n", ans[i]);
    }
    return 0;
}
