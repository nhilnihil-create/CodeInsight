#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,X,g,tmp;
    cin >> N >> X;

    vector<int> x(N);
    
    for(int i=0;i<N;i++) {
        cin >> x[i];
    }

    if(N == 1) {
        cout << abs(x[0]-X) << endl;
        return 0;
    }

    sort(x.begin(), x.end());
    g = X - x[0];
    for(int i=1;i<N;i++) {
        g=__gcd(g,x[i]-x[0]);
    }
    cout << g << endl;
    
    return 0;
}
