#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (((a) < (b)) ? (b) : (a))
#define abs(a) (((a) < 0) ? (-(a)) : (a))
int main(void) {
    int64_t N,Z,W;

    cin >> N >> Z >> W;

    vector<int64_t> a(N);
    for(int i=0;i<N;i++) {
        cin >> a[i];
    }
    
    if(N == 1) {
        cout << abs(W-a[0]) << "\n";
    } else {
        cout << max(abs(a[a.size()-1]-W),abs(a[a.size()-1]-a[a.size()-2])) << "\n";
    }
    return 0;
}
