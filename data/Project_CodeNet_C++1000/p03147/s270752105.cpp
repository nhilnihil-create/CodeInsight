#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

bool isDone(vector<int> box)
{
    for (int i = 0; i < box.size(); i++)
    {
        if (box[i] != 0)
        {
            return false;
        }
    }
    return true;
}

bool isZero(vector<int> box)
{
    for (int i = 0; i < box.size(); i++)
    {
        if (box[i] == 0)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    int N;
    cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    int cnt = 0;
    while (isDone(h) == false)
    {
        if (isZero(h) == false)
        {
            // -1 from every pos
            for (int i = 0; i < N; i++)
            {
                h[i]--;
                // printf("%d ", h[i]);
            }
            // printf("\n");
        }
        else
        {
            bool start_found = false;
            bool goal_found = false;
            for (int i = 0; i < N; i++)
            {
                if (h[i] > 0)
                {
                    start_found = true;
                    h[i]--;
                }
                else if (h[i] == 0 && start_found == true)
                {
                    goal_found = true;
                }
                if (start_found == true && goal_found == true)
                {
                    break;
                }
            }
        }
        // for (int i = 0; i < N; i++)
        // {
        //     printf("%d ", h[i]);
        // }
        // printf("\n");
        cnt++;
    }
    cout << cnt << endl;
    return (0);
}