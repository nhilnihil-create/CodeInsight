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
    cout << N - 1 << endl;
    bool rightMale = isMale();
    while (left < right) {
        int mid = (left + right) / 2;
        cout << mid << endl;
        bool midMale = isMale();
        bool vacantLeft = false;
        bool vacantRight = false;
        if ((mid - left) % 2 == 0) {
            if (leftMale != midMale) {
                vacantLeft = true;
            }
        } else {
            if (leftMale == midMale) {
                vacantLeft = true;
            }
        }
        if ((right - mid) % 2 == 0) {
            if (rightMale != midMale) {
                vacantRight = true;
            }
        } else {
            if (rightMale == midMale) {
                vacantRight = true;
            }
        }
        if (vacantLeft) {
            right = mid;
            rightMale = midMale;
        } else {
            left = mid;
            leftMale = midMale;
        }
    }
}