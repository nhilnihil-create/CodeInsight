#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>
#include <assert.h>
using namespace std;

const unsigned long long MOD = (unsigned long long)(1e9 + 7);

#define FROM_0(i, n) for(int i = 0; i < (n); i++)
#define FROM_S(i, s, e) for(int i = (s); i < (e); i++)
#define ITER_BEGIN_END(iter, vec) for(auto iter = vec.begin(); iter != vec.end(); iter++)

int main()
{
    int n;
    cin >> n;
    unsigned long long count[] = { 0, 0, 0, 0, 0 };
    FROM_0(i, n)
    {
        string s;
        cin >> s;
        switch (s[0])
        {
        case 'M':
            count[0]++;
            break;
        case 'A':
            count[1]++;
            break;
        case 'R':
            count[2]++;
            break;
        case 'C':
            count[3]++;
            break;
        case 'H':
            count[4]++;
            break;
        default:
            break;
        }
    }
    unsigned long long sum = 0;
    FROM_0(i, 5)
    {
        FROM_S(j, i + 1, 5)
        {
            FROM_S(k, j + 1, 5)
            {
                sum += count[i] * count[j] * count[k];
            }
        }
    }
    cout << sum << endl;

    return 0;
}
