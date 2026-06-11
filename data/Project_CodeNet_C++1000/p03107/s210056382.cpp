#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    string S;
    cin >> S;

    int length = S.size();
    int half = length / 2;
    int ans;
    if (length % 2 == 0)
    {
        vector<int> left(2);
        vector<int> right(2);
        for (int i = 0; i < half; i++)
        {
            if (S[i] == '0')
            {
                left[0]++;
            }
            else
            {
                left[1]++;
            }
        }
        for (int i = half; i < S.size(); i++)
        {
            if (S[i] == '0')
            {
                right[0]++;
            }
            else
            {
                right[1]++;
            }
        }
        ans = min(left[0], right[1]) + min(left[1], right[0]);
    }
    else
    {
        int ans1, ans2;
        vector<int> left1(2);
        vector<int> right1(2);
        // left 6 right 7
        for (int i = 0; i < half; i++)
        {
            if (S[i] == '0')
            {
                left1[0]++;
            }
            else
            {
                left1[1]++;
            }
        }
        for (int i = half; i < S.size(); i++)
        {
            if (S[i] == '0')
            {
                right1[0]++;
            }
            else
            {
                right1[1]++;
            }
        }
        ans1 = min(left1[0], right1[1]) + min(left1[1], right1[0]);

        vector<int> left2(2);
        vector<int> right2(2);
        // left 7 right 6
        for (int i = 0; i <= half; i++)
        {
            if (S[i] == '0')
            {
                left2[0]++;
            }
            else
            {
                left2[1]++;
            }
        }
        for (int i = half + 1; i < S.size(); i++)
        {
            if (S[i] == '0')
            {
                right2[0]++;
            }
            else
            {
                right2[1]++;
            }
        }
        ans1 = min(left2[0], right2[1]) + min(left2[1], right2[0]);
        ans = max(ans1, ans2);
    }
    cout << ans * 2 << endl;
}