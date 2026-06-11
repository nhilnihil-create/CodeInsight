#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int x;
    cin >> x;
    int ans=1;
    if (x >= 4) {
        for (int i=2; i<floor(sqrt(x))+1; i++){
            int j=2;
            while (pow(i, j) <= x) {
                ans = fmax(ans, pow(i, j));
                j += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}