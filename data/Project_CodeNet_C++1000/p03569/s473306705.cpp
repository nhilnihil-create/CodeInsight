#include <cmath>
#include <iostream>
#include <string>
using namespace std;

bool palindrome_or_not(string A)
{
    bool t_or_f = true;
    for (int i = 0; i <= (A.size() - 1) / 2; i++)
    {
        if (A[i] != A[A.size() - 1 - i]) t_or_f = false;
    }
    return t_or_f;
}

int main()
{
    string S; cin >> S;

    string S_excluding_x = "";
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != 'x')
        {
            S_excluding_x += S[i];
        }
    }

    if (S_excluding_x.size() == 0) // S = "xxxx...xxx"
    {
        cout << 0 << endl;
        return 0;
    }
    
    if (! palindrome_or_not(S_excluding_x))
    {
        cout << -1 << endl;
        return 0;
    }

    // 回文の中心を探す
    int p_S = -1, p_S_x = -1;
    int center[2] = {};
    for (int i = 0; i < S.size(); i++)
    {
        p_S++;
        if (S[p_S] != 'x')
        {
            p_S_x++;
            if (p_S_x == (S_excluding_x.size() - 1) / 2)
            {
                center[0] = p_S;
            }
            if (p_S_x == S_excluding_x.size() / 2)
            {
                center[1] = p_S;
                break;
            }
        }
    }
    // 回文の中心は
    // S_excluding_xの長さが奇数の時、center[0]（= center[1]）
    // _excluding_xの長さが偶数の時、center[0]とcenter[1]の中心

    // S[center[0]] ～ S[0] と S[center[1]] ～ S[S.size() - 1]を比較し
    //足りない'x'を補充する
    int ans = 0;
    int start_left = center[0], goal_left = center[0] - 1;
    int start_right = center[1], goal_right = center[1] + 1;

    // Sの両端に'a'をくっつける
    S = 'a' + S + 'a';
    start_left++; goal_left++;
    start_right++; goal_right++;

    while (goal_left != 0 || goal_right != S.size() - 1)
    {
        while (S[goal_left] == 'x')
        {
            goal_left--;
        }
        while (S[goal_right] == 'x')
        {
            goal_right++;
        }

        ans += abs(abs(goal_left - start_left) - abs(goal_right - start_right));

        start_left = goal_left;
        start_right = goal_right;

        if (goal_left != 0) goal_left--;
        if (goal_right != S.size() - 1) goal_right++;
    }

    cout << ans << endl;

    return 0;
}