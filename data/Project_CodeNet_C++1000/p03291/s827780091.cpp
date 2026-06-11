#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int64_t Prev(const vector<int64_t> &count, char ch, int64_t possibilities)
{
    if (ch == 'A') {
        return possibilities;
    }
    return count[ch - 'A' - 1];
}

int main()
{
    string str;
    getline(cin, str);

    constexpr int64_t kMod = 1e9 + 7;
    vector<int64_t> count(3, 0);

    int64_t possibilities = 1;
    for (const auto &ch : str) {
        if (ch != '?') {
            count[ch - 'A'] += Prev(count, ch, possibilities);
            count[ch - 'A'] %= kMod;
            continue;
        }

        vector<int64_t> new_count(3);
        for (char i = 'A'; i <= 'C'; i += 1) {
            new_count[i - 'A'] = 3 * count[i - 'A'] + Prev(count, i, possibilities);
            new_count[i - 'A'] %= kMod;
        }
        count = new_count;
        possibilities *= 3;
        possibilities %= kMod;
    }

    cout << count[2] << "\n";
    return 0;
}
