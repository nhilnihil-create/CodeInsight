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

#ifdef DEBUG
#define Dump(x) cerr << #x << " = " << x << endl;
#define Dumps(x) cerr << #x << " : { " << join(x.begin(), x.end()) << " }" << endl;
#else
#define Dump(x)
#define Dumps(x)
#endif

int main()
{
    int R;
    cin >> R;

    if (R < 1200)      cout << "ABC";
    else if (R < 2800) cout << "ARC";
    else               cout << "AGC";
    cout << endl;
}
