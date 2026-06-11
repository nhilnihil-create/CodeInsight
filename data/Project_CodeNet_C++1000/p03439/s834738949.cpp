#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool isMale() {
    string result;
    cin >> result;
    if (result == "Vacant") {
        exit(0);
    }
    return result == "Male";
}

int main() {
    int N;
    cin >> N;
    int left = 0;
    int right = N - 1;
    cout << 0 << endl;
    bool leftMale = isMale();
    while (left < right) {
        int mid = (left + right + 1) / 2;
        cout << mid << endl;
        bool midMale = isMale();
        bool vacantLeft = false;
        if ((mid - left) % 2 == 0) {
            if (leftMale != midMale) {
                vacantLeft = true;
            }
        } else {
            if (leftMale == midMale) {
                vacantLeft = true;
            }
        }
        if (vacantLeft) {
            right = mid;
        } else {
            left = mid;
            leftMale = midMale;
        }
    }
}