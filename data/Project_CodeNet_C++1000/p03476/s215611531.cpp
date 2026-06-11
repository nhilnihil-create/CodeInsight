#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
typedef long long ll;
#define downque(que) priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;

int main()
{
    //input
    int q;
    cin >> q;

    //search brothers of 2017

    int max_r = 1e5 + 1;
    
    //素数かどうかの判定表
    vector<bool> Prime(max_r, 1);
    //１からiまでの2017に似てる素数の個数を保存（累積和）
    vector<int> Sum(max_r, 0);

    //１．素数かどうか判定表を作成
    //2.それを用いて、NとN+1/2が素数な数字の個数を数える

    //１．素数かどうか判定表を作成
    Prime[0] = false;
    Prime[1] = false;

    //合成数（素数ではない）を見つけていく
    for (int i = 2; i * i <= max_r; i++)
    {
        //iの倍数を消す
        for (int j = 2 * i; j <= max_r; j += i)
        {
            Prime[j] = false;
        }
    }

    //2.Primeを用いて、NとN+1/2が素数な数字の個数を数える
    REP(i, max_r)
    {
        int a = (i + 1) / 2;
        if (Prime[i] && Prime[a])
            Sum[i + 1] = Sum[i] + 1;
        else
        {
            Sum[i + 1] = Sum[i];
        }
    }

    //output
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << Sum[r + 1] - Sum[l] << endl;
    }
}
