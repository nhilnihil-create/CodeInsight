#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <functional>
#include <math.h>
#include <iomanip>
using namespace std;

int main(void)
{
    long int N;
    vector<int> P;
    P.push_back(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        P.push_back(tmp);
    }
    int max = *max_element(P.begin(), P.end());

    int sum = 0;
    for (int i = max; i >= 0; i--)
    {
        vector<int> P2(P);
        for (int j = 1; j <= N; j++)
        {
            if (P[j] == i)
            {
                if (P[j - 1] < P[j])
                {
                    sum++;
                }
                P2[j]--;
            }
        }
        P = P2;
    }
    cout << sum << endl;
    return 0;
}