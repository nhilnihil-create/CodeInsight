#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    vector<char> C1(3);
    vector<char> C2(3);
    cin >> C1.at(0) >> C1.at(1) >> C1.at(2) >> C2.at(0) >> C2.at(1) >> C2.at(2);
    cout << (C1.at(0) == C2.at(2) && C1.at(1) == C2.at(1) && C1.at(2) == C2.at(0) ? "YES" : "NO") << endl;
}