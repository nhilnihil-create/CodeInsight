#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int64_t> A(k);
    copy_n(istream_iterator<int64_t>(cin), k, A.begin());

    int64_t l = 2, r = 2; 
    for (int i = k - 1; i >= 0; i--){
        auto a = A[i];
        if (l % a != 0)
            l = l / a * a + a;
        if (r % a != 0)
            r = r / a  * a;
        if (l > r){
            cout << -1 << endl;
            return 0;
        }
        r += a - 1;
    }

    cout << l << " " << r << endl;
}