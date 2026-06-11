#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 
int main()
{
    // 入力
    map<int, int> mp1;
    map<int, int> mp2;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if(i % 2 == 0) mp1[a]++;
        else mp2[a]++;
    }

    // 最頻値から答えを求める１
    int max1 = 0;
    int key = 0;
    for(pair<int, int> m: mp1)
    {
        if(m.second > max1)
        {
            max1 = m.second;
            key = m.first;
        }
    }
    int max2 = 0;
    for(pair<int, int> m: mp2)
    {
        // mp1の最頻値となるkeyとは異なる値を選ぶ
        if(m.second > max2 && m.first != key) max2 = m.second;
    }
    int ans1 = (N/2 - max1) + (N/2 - max2);

    // 最頻値から答えを求める２
    max1 = 0;
    key = 0;
    for(pair<int, int> m: mp2)
    {
        if(m.second > max1)
        {
            max1 = m.second;
            key = m.first;
        }
    }
    max2 = 0;
    for(pair<int, int> m: mp1)
    {
        // mp2の最頻値となるkeyとは異なる値を選ぶ
        if(m.second > max2 && m.first != key) max2 = m.second;
    }
    int ans2 = (N/2 - max1) + (N/2 - max2);

    // 答えを出力
    int ans = min(ans1, ans2);
    cout << ans << endl;
    return 0;
}