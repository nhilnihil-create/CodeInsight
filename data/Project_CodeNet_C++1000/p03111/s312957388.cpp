#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, A, B, C;
int l[10];
const int INF = 1e+9;

int solve(int i, int a, int b, int c){
    if(i == n){
        if(a == 0 || b == 0 || c == 0)
            return INF;
        else
            return abs(a - A) + abs(b - B) + abs(c - C) - 30;
    }
    int res1 = solve(i+1, a, b, c);
    int res2 = solve(i+1, a + l[i], b, c) + 10;
    int res3 = solve(i+1, a, b + l[i], c) + 10;
    int res4 = solve(i+1, a, b, c + l[i]) + 10;
    return min({res1, res2, res3, res4});
}

int main(){
    cin >> n >> A >> B >> C;
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    cout << solve(0, 0, 0, 0) << endl;
    return 0;
}