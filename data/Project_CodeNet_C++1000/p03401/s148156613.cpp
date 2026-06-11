#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x) // decltypeで型取得、引数があればva_argsのところに入れる
using namespace std;
typedef long long ll; // long longをllでかけるようにした
const int INF = 1e9;

int main(void){
    int n; cin >> n;
    vector<int> spot(n + 2),  expect(n + 2), distance(n + 2);
    ll sumall = 0;
    REP(i, n){
        cin >> spot[i + 1];
        distance[i + 1] = abs(spot[i + 1] - spot[i]);
        sumall += abs(spot[i + 1] - spot[i]);
    }
    sumall += abs(spot[n]);
    distance[n + 1] = abs(spot[n]);
    for(int i = 1; i <= n; i++){
        expect[i] = abs(spot[i + 1] - spot[i - 1]);
    }
    REP(i, n){
        cout << sumall - (distance[i + 1] + distance[i + 2]) + expect[i + 1] << endl;
    }
}