#include "bits/stdc++.h"

using namespace std;

void Main() {
    vector<int> edges(3, 0);
    cin >> edges[0] >> edges[1] >> edges[2];


    sort(edges.begin(), edges.end());
    cout << (0.5 * edges[0] * edges[1]) << endl;
}

int main() {
    //std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
