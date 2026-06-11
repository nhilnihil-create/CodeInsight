#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,H;
    cin >> N >> H;

    vector<int> a(N);
    vector<int> b(N);
    for(int i=0;i<N;i++) {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt = 0;
    vector<int>::iterator it = upper_bound(b.begin(), b.end(), a[N-1]);
    int tmax = distance(it, b.end());
    for(int i=0;i<tmax;i++){
        H -= b[b.size()- i -1];
        cnt++;
        if(H <= 0) {
            cout << cnt << endl;
            return 0;
        }
    }

    cnt += (H/a[N-1]);
    if(H%a[N-1]) cnt++;
    cout << cnt << endl;

    return 0;
}
