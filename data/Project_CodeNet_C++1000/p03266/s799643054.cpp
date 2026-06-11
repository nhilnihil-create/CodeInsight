#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

template <class It> string join(It i1, It i2)
{
    ostringstream ss;
    for (auto it = i1; it != i2; ++it)
        ss << ((it == i1) ? "" : ", ") << (*it);
    return ss.str();
}

void Print() { cout << endl; }
template <class Head, class... Args> void Print(Head &&head, Args&&... args)
{
    cout << head;
    Print(args...);
}

#ifdef DEBUG
#define Dump(x) cerr << #x << " = " << x << endl;
#define Dumps(x) cerr << #x << " : { " << join(x.begin(), x.end()) << " }" << endl;
#else
#define Dump(x)
#define Dumps(x)
#endif


long pow3(long x) { return x * x * x; }


int main()
{
    long N, K;
    cin >> N >> K;

    size_t out = 0;
    if (K <= N)
        out += pow3(N / K);
    if (K % 2 == 0)
        out += pow3((N + K / 2) / K);

    cout << out << endl;
}
