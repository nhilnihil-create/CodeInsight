#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int N;

void func(ll now, int judge, ll &cnt){
    if(now > N) return;
    if(judge == 0b111) cnt++;
    func(now * 10 + 3, judge | 0b001, cnt);
    func(now * 10 + 5, judge | 0b010, cnt);
    func(now * 10 + 7, judge | 0b100, cnt);
}
int main() {
    cin >> N;
    ll res = 0;
    func(0, 0, res);
    cout << res << endl;
}