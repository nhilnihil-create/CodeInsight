#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

int main() {
    string s;
    cin >> s;

    auto first = (s[0] - '0') * 10 + (s[1] - '0');
    auto second = (s[2] - '0') * 10 + (s[3] - '0');

    auto fm = (1 <= first && first <= 12);
    auto sm = (1 <= second && second <= 12);

    auto str = (fm && sm) ? "AMBIGUOUS" : fm ? "MMYY" : sm ? "YYMM" : "NA";

    cout << str << endl;
    return 0;
}
