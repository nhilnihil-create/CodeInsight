#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> C(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        C[i] = a+b;
        sum += a;
    }
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    for (int i = 1; i < N; i+=2) sum -= C[i];
    cout << sum << endl;
    return 0;
}