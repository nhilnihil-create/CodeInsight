#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int cnt = 0;

    cin >> N;

    // 複数要素を取得
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec.at(i);
    }
    int flag = 0;

    while (1)
    {
        // 複数要素が偶数かを判定
        for (int i = 0; i < vec.size(); i++)
        {
            // 奇数の場合
            if (vec.at(i) % 2 != 0)
            {
                flag = 1;
                break;
            }
            // 最後のループの場合
            else if (i + 1 == vec.size())
            {

                cnt++;
            }
            else
            {
                vec.at(i) /= 2;
            }
        }
        if (flag)
        {
            break;
        }
    }
    cout << cnt;
}
