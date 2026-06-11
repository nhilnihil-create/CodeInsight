#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D ,X;
    cin >> N >> D >> X;
    int count = X;

    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];

    for(int i=0; i<N; i++) {
        int day = 1;
        while(day <= D) {
            day += v[i];
            count++;
        }
    }
    cout <<count << endl;
}
