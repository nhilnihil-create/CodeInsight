#include <bits/stdc++.h>
using namespace std;
int main(){
        int n; cin >> n;
        int sum = 0;
        for (int x = 0; x < n; ++x){
            int q; cin >> q;
            while (q % 2 == 0){
                q /= 2;
                sum++;
            }
        }
        cout << sum << endl;
    return 0;
}
