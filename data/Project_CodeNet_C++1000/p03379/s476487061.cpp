#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    vector<int> X(N);
    vector<int> temp(N);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    temp = X;
    sort(temp.begin(), temp.end(), greater<int>());
    int left = temp[N / 2 - 1];
    int right = temp[N / 2];

    int location;
    for (int i = 0; i < N; i++)
    {
        if (X[i] <= right)
        {
            printf("%d\n", left);
        }
        else
        {
            printf("%d\n", right);
        }
    }
    return (0);
}