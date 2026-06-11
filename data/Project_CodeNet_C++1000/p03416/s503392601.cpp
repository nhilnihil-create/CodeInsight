#include <iostream>
#include <string>
using namespace std;


bool check(int x) {

    string S = to_string(x);
    auto first = S.begin();
    auto last = S.end();
    --last;

    while (first < last) {
        if(*first != *last) {
            return false;
        }
        ++first;
        --last;
    }
    return true;
}


int main() {
    int A, B;
    cin >> A >> B;
    int num = 0;

    for (int x=A; x<=B; ++x) {
        if (check(x)) {
            ++num;
        }
    }

    cout << num << endl;
}
