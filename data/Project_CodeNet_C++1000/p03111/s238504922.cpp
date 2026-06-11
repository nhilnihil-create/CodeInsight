#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int n, A, B, C;
vector<int> l;

int solve(int i, int a, int b, int c){
    if(i == n){
        if(a == 0 || b == 0 || c == 0) return INF;
        return abs(a - A) + abs(b - B) + abs(c - C);
    }
    int res = solve(i+1, a, b, c);
    res = min(res, solve(i+1, a+l.at(i), b, c) + (a? 10:0));
    res = min(res, solve(i+1, a, b+l.at(i), c) + (b? 10:0));
    res = min(res, solve(i+1, a, b, c+l.at(i)) + (c? 10:0));
    return res;
}

int main(){
    cin >> n >> A >> B >> C;
    l.resize(n);
    for(int i = 0; i < n; i++) cin >> l.at(i);
    cout << solve(0, 0, 0, 0) << endl;
}