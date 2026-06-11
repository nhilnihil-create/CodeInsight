#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int L, n;
    vector<int> u, v, w;
    cin >> L;
    for(n = 1; (1<<n) <= L; n++);
    for(int i = 1; i < n; i++){
        u.push_back(i);
        u.push_back(i);
        v.push_back(i+1);
        v.push_back(i+1);
        w.push_back(0);
        w.push_back(1<<(i-1));
        if(((L>>(i-1))&1) == 1){
            u.push_back(i);
            v.push_back(n);
            w.push_back(L-(L%(1<<i)));
        }
    }
    int m = u.size();
    cout << n << " " << m << endl;
    for(int i = 0; i < m; i++){
        cout << u[i] << " " << v[i] << " " << w[i] << endl;
    }
}
