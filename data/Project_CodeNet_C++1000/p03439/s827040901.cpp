#include <iostream>
using namespace std;

string query(int i) {
    cout << i << endl;
    string result;
    cin >> result;
    return result;
};

int main() {
    int n;
    cin >> n;
    int begin = 0, end = n - 1;
    string head = query(begin);
    if (head != "Vacant") {
        while (true) {
            auto mid = (begin + end + 1) / 2;
            auto current = query(mid);
            if (current == "Vacant") {
                break;
            }
            if ((current == head) != (begin % 2 == mid % 2)) {
                end = mid;
            } else {
                begin = mid;
                swap(head, current);
            }
        }
    }
    return 0;
}
