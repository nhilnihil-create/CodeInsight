#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int abmax_pos = 0;
    int abmax = abs(a[0]);
    for (int i = 1; i < N; i++) {
        if (abmax < abs(a[i])) {
            abmax_pos = i;
            abmax = abs(a[i]);
        }
    }
    if (a[abmax_pos] >= 0) {
        cout << 2*N-1 << endl;
        for (int i = 1; i <= N; i++) cout << abmax_pos+1 << " " << i << endl;
        for (int i = 1; i <= N-1; i++) cout << i << " " << i+1 << endl;
        return 0;
    }
    else if (a[abmax_pos] < 0) {
        cout << 2*N-1 << endl;
        for (int i = 1; i <= N; i++) cout << abmax_pos+1 << " " << i << endl;
        for (int i = N-1; i >= 1; i--) cout << i+1 << " " << i << endl;
        return 0;
    }
    return 0;
}