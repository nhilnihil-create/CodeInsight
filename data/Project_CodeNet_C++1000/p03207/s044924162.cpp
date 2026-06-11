#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int sum = 0;
    int maxp = 0;
    cin >> N;

    vector<int> p(N);
    for(int i=0;i<N;i++) {
        cin >> p[i];
        sum += p[i];
        if(maxp <p[i]) {
            maxp = p[i];
        }
    }

    cout << sum - (maxp/2) << endl;

    return 0;
}
