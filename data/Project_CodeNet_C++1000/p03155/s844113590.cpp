#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,H,W; cin >> N >> H >> W;
    cout << (N-H+1)*(N-W+1) << '\n';
}