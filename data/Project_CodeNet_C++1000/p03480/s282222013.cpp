#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int res = str.size();
    for (size_t i = 0; i + 1 < str.size(); i += 1) {
        if (str[i] != str[i + 1]) {
            res = min<int>(res, max(i + 1, str.size() - i - 1));
        }
    }

    cout << res << "\n";
    return 0;
}
