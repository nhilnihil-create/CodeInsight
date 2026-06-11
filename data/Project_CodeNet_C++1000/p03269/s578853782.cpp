#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll L;
    cin >> L;
    vector<tll> answers;
    ll nodeIndex = 1;
    ll filled = 1; //半開
    while (filled * 2 <= L)
    {
        answers.emplace_back(nodeIndex, nodeIndex + 1, 0);
        answers.emplace_back(nodeIndex, nodeIndex + 1, filled);
        nodeIndex++;
        filled *= 2;
    }
    while (filled < L)
    {
        ll targetIndex = 1;
        ll targetValue = 1;
        while (targetValue <= L - filled)
        {
            targetValue *= 2;
            targetIndex++;
        }
        targetValue /= 2;
        targetIndex--;
        answers.emplace_back(targetIndex, nodeIndex, filled);
        filled += targetValue;
    }
    cout << nodeIndex << " " << answers.size() << " " << endl;
    for (auto answer : answers)
    {
        ll node1, node2, value;
        tie(node1, node2, value) = answer;
        cout << node1 << " " << node2 << " " << value << endl;
    }
    return 0;
}
