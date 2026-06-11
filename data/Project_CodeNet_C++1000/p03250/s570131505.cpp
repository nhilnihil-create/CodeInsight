#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int A,B,C;cin>>A>>B>>C;
    vector<int> vc;
    vc.push_back(A);
    vc.push_back(B);
    vc.push_back(C);
    int mx = -1;
    do {
        int a = vc.at(0) + (vc.at(1) * 10 + vc.at(2));
        int b = (vc.at(0) * 10 + vc.at(1)) + vc.at(2);
        if (mx < max(a, b)) mx = max(a, b);
    } while (next_permutation(vc.begin(), vc.end()));
    cout << mx << endl;
    return 0;
}