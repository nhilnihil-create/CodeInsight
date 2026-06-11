#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
typedef long long ll;


int main(){
    int n, k;
    cin >> n >> k;
    if (k % 2 != 0){
        cout << ll(pow(n / k, 3)) << endl;
    }
    else {
        int t = k / 2;
        int odd = (n / t + 1) / 2;
        cout << ll(pow(n / k, 3)) + ll(pow(odd, 3)) << endl;
    }
    return 0;
}