#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    vector<int> ABC = {A,B,C};
    sort(ABC.begin(), ABC.end());

    for(int i = 0; i < K; i++) {
        ABC.at(2) *= 2;
    } 

    int total = ABC.at(0) + ABC.at(1) + ABC.at(2);
    cout << total << endl;

}