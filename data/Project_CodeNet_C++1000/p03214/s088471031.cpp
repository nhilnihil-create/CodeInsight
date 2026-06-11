#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = -1;
    int dist = sum;
    for (int i = 0; i < N; i++) {
        if (dist > abs(sum-a[i]*N)) {
            dist = abs(sum-a[i]*N);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}