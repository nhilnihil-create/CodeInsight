#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << (A + B == C + D ? "Balanced" : (A + B > C + D) ? "Left" : "Right") << endl;
}