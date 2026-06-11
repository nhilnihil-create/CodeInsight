#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> a(N);
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] -= i + 1;
        sum += a[i];
    }
    sort(a.begin(), a.end());
    long long res;
    if(N % 2 == 1) res = a[N / 2];
    else res = (a[N / 2] + a[N / 2 - 1]) / 2;
    long long ans = 0;
    for(int i = 0; i < N; i++) ans += abs(a[i] - res);
    cout << ans << endl;
}