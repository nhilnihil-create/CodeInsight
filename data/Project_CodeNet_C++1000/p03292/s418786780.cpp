#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int main(void) {
    int A1,A2,A3;cin>>A1>>A2>>A3;
    vector<int> vc;
    vc.push_back(abs(A1 - A2) + abs(A2 - A3));
    vc.push_back(abs(A1 - A3) + abs(A2 - A3));
    vc.push_back(abs(A2 - A3) + abs(A3 - A1));
    vc.push_back(abs(A2 - A1) + abs(A3 - A1));
    vc.push_back(abs(A3 - A1) + abs(A1 - A2));
    vc.push_back(abs(A3 - A2) + abs(A2 - A1));
    sort(vc.begin(), vc.end());
    cout << vc.at(0) << endl;
    return 0;
}