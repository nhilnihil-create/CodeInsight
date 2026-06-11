#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> o;
    int tmp, tcost = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> tmp;
        o.push_back(tmp);
        tcost += ((tmp+9) / 10) * 10;
    }
    tmp = 644; 
    for (int i: o) {
        tmp = min(tmp, tcost - ((i+9) / 10) * 10 + i);
    }
    tcost = tmp;
    cout << tcost << endl;
    return 0;
}
