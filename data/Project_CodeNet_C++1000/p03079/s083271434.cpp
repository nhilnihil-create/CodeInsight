#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++) //for文マクロ
using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P; //ペア　タイプでふ
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B && B == C)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}