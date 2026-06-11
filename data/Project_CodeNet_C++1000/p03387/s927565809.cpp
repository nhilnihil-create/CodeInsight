#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {;
    vector<int> num{};
    int ret = 0, tmp;
    for (int i = 0; i < 3; i++) {cin >>tmp; num.push_back(tmp);}
    while (num[0] != num[1] || num[1] != num[2]) {
        sort(num.begin(), num.end());
        if (num[2]-num[0] > 1) {ret++; num[0]+=2;}
        else if (num[0]==num[1]) {ret += 1; break;}
        else if (num[0]!=num[1]) {ret += 2; break;}
    }
    cout << ret << endl;
    return 0;
}