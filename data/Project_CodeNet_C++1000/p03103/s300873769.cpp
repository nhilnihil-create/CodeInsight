#include <bits/stdc++.h>
using namespace std;

int main(){
    long n, m;
    cin >> n >> m;
    
    vector<pair<long, long>> vec(n);
    for (long i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        vec.at(i) = make_pair(a, b);
    }
    sort(vec.begin(),vec.end());
    long sum = 0;
    for (long i = 0; i < n; i++) {
        long buf = min(vec.at(i).second,m);
        sum += buf * vec.at(i).first;
        m -= buf;
        if (m <= 0) {
            break;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
