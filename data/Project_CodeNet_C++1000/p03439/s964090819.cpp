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
        if ((mid - left) % 2 == (leftMale == midMale)) {
            right = mid;
        } else {
            left = mid;
            leftMale = midMale;
        }
    }
}