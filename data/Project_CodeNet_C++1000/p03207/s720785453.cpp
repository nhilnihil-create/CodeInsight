#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> p(N);
    for (int i=0; i<N; i++) cin >> p.at(i);
    sort(p.begin(), p.end());
    int res=0;
    for (int i=0; i<N-1; i++) {
        res += p.at(i);
    }
    cout << res+p.at(N-1)/2;
}