#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <list>
#include <bitset>
#include <cstdlib>
#include <map>
using ll = long long int;
using namespace std;

int main()
{
    int N, A, B, a = 0, b = 0, c = 0;
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp <= A)
        {
            a++;
        }
        else if ((A < tmp) && (tmp <= B))
        {
            b++;
        }
        else
        {
            c++;
        }
    }
    cout << min(a, min(b, c)) << endl;

    return 0;
}