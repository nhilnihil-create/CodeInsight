#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++) //for文マクロ
using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P; //ペア　タイプでふ

int main()
{
    // int A, B, T;
    // cin >> A;
    // cin >> B;
    // cin >> T;
    // cout << (int)(B * ((T - T % A) / A));
    int A, B, C;
    cin >> A >> B >> C;
    if (A > B)
        swap(A, B);
    if (A < C && C < B)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}