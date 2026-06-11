#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> time(n - 1, vector<int> (3));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> time.at(i).at(j);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a = 0;
        a += time.at(i).at(1) + time.at(i).at(0);
        for (int j = i + 1; j < n - 1; j++) {
            if (a <= time.at(j).at(1)) {
                a = time.at(j).at(1);
            }
            else {
                int c = a / time.at(j).at(2);
                if (a % time.at(j).at(2) != 0) c++;
                a = c * time.at(j).at(2);
                }
            a += time.at(j).at(0);
        }
        cout << a << endl;
    }
    cout << 0 << endl;
}