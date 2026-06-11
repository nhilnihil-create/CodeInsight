// 問題の URL を書いておく
// 

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <numeric>
#include <array>
#include <cmath>
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

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

const int Size = 1000001;

array<int, Size> g_Table{};

array<int, Size> g_PrimeTable{};

bool IsPrimeImpl(int n)
{
    if(n < 2)
    {
        return false;
    }
    if(n == 2)
    {
        return true;
    }
    if(n % 2 == 0)
    {
        return false;
    }
    for(int i = 3; i <= static_cast<int>(sqrt(n)); i += 2)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool IsPrime(int n)
{
    if(g_PrimeTable[n] == 1)
    {
        return false;
    }
    if(g_PrimeTable[n] == 2)
    {
        return true;
    }
    auto isPrime = IsPrimeImpl(n);
    g_PrimeTable[n] = isPrime ? 2 : 1;
    return isPrime;
}

void SetupTable()
{
    g_Table[2] = 0;
    g_Table[3] = 1;
    for(int i = 5; i < Size - 1; i += 2)
    {
        g_Table[i - 1] = g_Table[i - 2];
        if(IsPrime(i) && IsPrime((i + 1) / 2))
        {
            g_Table[i] = g_Table[i - 1] + 1;
        }
        else
        {
            g_Table[i] = g_Table[i - 1];
        }
    }
}

int main(int, const char**)
{
    SetupTable();
#if 0
    rep(i, 15)
    {
        printf("%d: %d\n", i, g_Table[i]);
//        cout << g_Table[i] << endl;
    }
#endif
#if 0
    rep(i, 15)
    {
        printf("%d: %d\n", i, g_PrimeTable[i]);
//        cout << g_Table[i] << endl;
    }
#endif
    int q;
    cin >> q;
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        cout << g_Table[r] - g_Table[l - 1] << endl;
    }
    return 0;
}
