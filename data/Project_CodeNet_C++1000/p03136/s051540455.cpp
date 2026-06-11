#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> l(n);

    int tmp = 0;
    int i = 0;
    int max = 0;
    int sum = 0;
    while(cin >> tmp) {
        if(max < tmp) {
            max = tmp;
        }

        sum += tmp;

        l[i] = tmp;
        i ++;
        if(i >= n) {
            break;
        }
    }

    sum -= max;

    if(sum > max) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



}