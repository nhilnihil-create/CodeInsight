#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    double n,k;
    cin >> n >> k;
    double prob = 0;
    for (int i = 1; i < n+1; i++)
    {
        int score = i;
        double sum = 1;
        while (score < k)
        {
            score *= 2;
            sum *= 0.5;
        }
        prob += sum/n;
    }
    cout << fixed << setprecision(10) << prob << endl;
}