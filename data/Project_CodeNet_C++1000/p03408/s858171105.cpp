#include <bits/stdc++.h>
using namespace std;
int N, M;

//map<key_type, value_type>で辞書型
//blueCard[i] == "orange"などの比較が可能
int getMaxValue(vector<int> count)
{
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (count[i] > max)
            max = count[i];
    }
    return max;
}

int main()
{
    cin >> N;
    map<int, string> blueCard;
    for (int i = 0; i < N; i++)
    {
        cin >> blueCard[i];
    }

    cin >> M;
    map<int, string> redCard;
    for (int i = 0; i < M; i++)
    {
        cin >> redCard[i];
    }

    vector<int> count(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (blueCard[i] == blueCard[j])
                count[i]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (blueCard[i] == redCard[j])
                count[i]--;
        }
    }
    int res = getMaxValue(count);
    cout << res << endl;
}
