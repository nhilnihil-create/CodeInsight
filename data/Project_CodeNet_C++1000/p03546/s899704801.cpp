// 問題の URL を書いておく
// 

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <numeric>
#include <array>
using namespace std;

//#define ENABLE_PRINT

template<typename T>
T Input()
{
    T v;
    cin >> v;
    return v;
}

template<typename T>
vector<T> InputVector(int n)
{
    vector<T> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    return v;
}

template<typename T>
void InputArray(T* begin, int n)
{
    for(int i = 0; i < n; ++i)
    {
        cin >> begin[i];
    }
}

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

int main(int, const char**)
{
    int h, w;
    cin >> h >> w;
    const int CN = 10;
    array<array<int, CN>, CN> c;
    for(int i = 0; i < CN; ++i)
    {
        for(int j = 0; j < CN; ++j)
        {
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < CN; ++i)
    {
        for(int j = 0; j < CN; ++j)
        {
            for(int k = 0; k < CN; ++k)
            {
                c[j][k] = min(c[j][k], c[j][i] + c[i][k]);
            }
        }
    }

    int cost = 0;
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            int v;
            cin >> v;
            if(v == 1 || v == -1)
            {
                continue;
            }
            cost += c[v][1];
        }
    }
    cout << cost << endl;
    return 0;
}
