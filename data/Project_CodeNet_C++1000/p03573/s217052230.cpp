#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A == B ? C : ((A == C) ? B : A)) << endl;
}