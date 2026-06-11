#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N; cin >> N;
    string S; cin >> S;

    int cnt_white = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == '.') cnt_white++;
    }

    // 「白白白・・・白白黒黒・・・黒黒黒」
    int change_left = 0, change_right = cnt_white;
    int ans = change_left + change_right;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == '.') change_right--;
        else change_left++;

        ans = min(ans, change_left + change_right);
    }

    cout << ans << endl;
    return 0;
}