#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

const unsigned long long BASE = (unsigned long long)(1e9 + 7);
int b[50];
int a[50];

#define FROM_0(i, n) for(int i = 0; i < (n); i++)
#define FROM_S(i, s, e) for(int i = (s); i < (e); i++)
#define ITER_BEGIN_END(iter, vec) for(auto iter = vec.begin(); iter < vec.end(); iter++)

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    FROM_0(i, m)
    {
        cin >> b[i];
    }
    int count = 0;
    FROM_0(i, n)
    {
        int sum = c;
        FROM_0(j, m)
        {
            cin >> a[j];
            sum += a[j] * b[j];
        }
        //cout << sum << endl;
        if (sum > 0)
            count++;
    }
    cout << count << endl;

    return 0;
}
