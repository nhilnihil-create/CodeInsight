#include<bits/stdc++.h>
using namespace std;
int main(){
        int n; cin >> n;
        int cnt = 0;
        int mn = 0;
        for (int x = 0; x < n; ++x){
            int q; cin >> q;
            if (q >= mn){
                cnt += q - mn;
            }
            mn = q;
        }
        cout << cnt << endl;
    return 0;
}
