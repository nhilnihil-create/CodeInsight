#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    map<string, int> score;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        score[s]++;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        score[s]--;
    }
    int max_score = 0;
    for (auto p : score)
    {
        max_score = max(max_score, p.second);
    }
    cout << max_score << endl;
    return 0;
}