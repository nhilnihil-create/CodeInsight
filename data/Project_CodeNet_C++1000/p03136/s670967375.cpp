#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int sum = 0;

    cin >> N;
    vector<int> L(N);
    for(int i=0;i<N;i++) {
        cin >> L[i];
        sum += L[i];
    }

    if((sum - *max_element(L.begin(),L.end())) > (sum/2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
