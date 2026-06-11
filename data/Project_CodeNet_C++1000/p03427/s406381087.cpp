#include <iostream>
#include <string>
using namespace std;

int main() {
    string n; cin >>n;
    int ret;
    ret = n[0] - '0';
    for (int i = 1; i < n.size(); i++) {
        if (n[i]=='9') {
            ret += 9;
        }
        else {
            ret -= 1;
            ret += (n.size()-i)*9;
            break;
        }
    }
    cout << ret << endl;
    return 0;
}