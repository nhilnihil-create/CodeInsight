#include<bits/stdc++.h>
#define int long long
using namespace std;

int N, C;
int x[100100], v[100100];
int rsum1[100100], rsum2[100100], lsum1[100100], lsum2[100100];
int r1[100100], r2[100100], l1[100100], l2[100100];

signed main()
{
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> v[i];
    }
    for(int i = 0; i < N; i++){
        rsum1[i + 1] += v[i] - x[i] + rsum1[i];
        rsum2[i + 1] += v[i] - 2 * x[i] + rsum2[i];
        if(i > 0){
            rsum1[i + 1] += x[i - 1];
            rsum2[i + 1] += 2 * x[i - 1];
        }
    }
    lsum1[N - 1] = v[N - 1] - (C - x[N - 1]);
    lsum2[N - 1] = v[N - 1] - 2 * (C - x[N - 1]);
    for(int i = N - 2; i >= 0; i--){
        lsum1[i] += lsum1[i + 1] + v[i] - (C - x[i]) + (C - x[i + 1]);
        lsum2[i] += lsum2[i + 1] + v[i] - 2 * (C - x[i]) + 2 * (C - x[i + 1]);
    }
    for(int i = 1; i <= N; i++){
        r1[i] = max(r1[i - 1], rsum1[i]);
        r2[i] = max(r2[i - 1], rsum2[i]);
    }
    for(int i = N - 1; i >= 0; i--){
        l1[i] = max(l1[i + 1], lsum1[i]);
        l2[i] = max(l2[i + 1], lsum2[i]);

    }
    int ans = 0ll;
    for(int i = 0; i < N; i++){
        ans = max(ans, r1[i]);
        ans = max(ans, l1[i]);
        ans = max(ans, r2[i] + l1[i]);
        ans = max(ans, l2[i] + r1[i]);
    }
    ans = max(ans, r1[N]);
    cout << ans << endl;



    return 0;
}
