#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,K;
    int mindiff = 0;
    int d;
    cin >> N >> K;

    vector<int> h(N);
    vector<int> diff(N-1);
    for(int i=0;i<N;i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    for(int i=1;i<N;i++) {
        diff[i-1] = h[i]-h[i-1];
    }

    for(int i=0;i<(K-1);i++) {
        mindiff += diff[i];
    }
//printf("cur:%d\n", mindiff);

    d = mindiff;
    for(int i=(K-1);i<diff.size();i++) {
        d += diff[i];
        d -= diff[i-(K-1)];
//printf("i:%d %d\n", i, d);
        if(mindiff > d) {
            mindiff = d;
        }
    }
    
    cout << mindiff << endl;

    return 0;
}
