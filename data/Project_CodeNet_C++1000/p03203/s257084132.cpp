#include <bits/stdc++.h>
using namespace std;

int main(void){
    long h, w, n;
    cin >> h >> w >> n;
    vector<long> v(static_cast<size_t>(h+1), LONG_MAX);
    for(long i=0; i<n; i++){
        long x, y;
        cin >> x >> y;
        v[x] = min(v[x], y);
    }
    long right = 1;
    for(long x=1; x<h; x++){
        if(v[x+1]<=right){
            cout << x << endl;
            return 0;
        }
        if(v[x+1]!=right+1){
            right++;
        }
    }
    cout << h << endl;
    return 0;
}
