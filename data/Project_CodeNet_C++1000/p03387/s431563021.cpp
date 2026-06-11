#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    sort(vec.begin(), vec.end());

    int moves = vec[2] - vec[1];
    vec[0] += moves;
    vec[1] += moves;

    int diff = vec[1] - vec[0];

    if (diff % 2 == 1)
        moves += (diff + 1) / 2 + 1;
    else
        moves += diff / 2;


    cout << moves;


    return 0;
}