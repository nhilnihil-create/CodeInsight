#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

    string s;

    cin >> s;

    int n = s.size();

    int left = 0;
    int right = n - 1;

    int sum = 0;

    while(1) {
        int lCount = left;
        int rCount = right;

        while(left < n && s[left] == 'x')left++;
        while(right >= 0 && s[right] == 'x')right--;

        if(s[left] != s[right]) {
            cout << -1 << endl;
            return 0;
        }

        sum += abs((left - lCount) - (rCount - right));


        left++;
        right--;

        if(left >= right)
            break;


    }

    cout << sum << endl;

    return 0;

}