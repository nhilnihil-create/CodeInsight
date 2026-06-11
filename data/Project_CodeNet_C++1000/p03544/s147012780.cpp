#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> contain(3);

    contain.at(0) = 2;
    contain.at(1) = 1;
    contain.at(2) = 1;
    for(int i=0; i<N-1; i++){
        contain.at(2) = contain.at(1)+contain.at(0);
        contain.at(0) = contain.at(1);
        contain.at(1) = contain.at(2);
    }

    cout << contain.at(2) << endl;
    return 0;

}
