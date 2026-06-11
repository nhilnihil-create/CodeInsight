#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, count=1;
    cin >> N;
    vector<int> v(N);

    for(int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for(int i=0; i < N-1; i++) {
        if(v[i] != v[i+1]) count++;
    }
    cout << count << endl;
}