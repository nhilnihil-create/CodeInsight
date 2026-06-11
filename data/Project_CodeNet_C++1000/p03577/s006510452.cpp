#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    int d = s.rfind("FESTIVAL");

    cout << s.substr(0, d) << endl;
}
