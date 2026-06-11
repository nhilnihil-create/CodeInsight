#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Q;
    cin >> Q;
    int MAXVAL = 1e5;
    vector<bool> prime(MAXVAL+1,true);
    prime[0] = false;
    prime[1] = false;
    for (int i=2;i<=MAXVAL;i++){
        for (int j=2*i;j<=MAXVAL;j+=i){
            prime[j] = false;
        }
    }
    vector<int> num(MAXVAL+1);
    for (int i=1;i<=MAXVAL;i+=2){
        if (prime[i] && prime[(i+1)/2]) num[i] = num[i-2] + 1;
        else num[i] = num[i-2];
    }
    for (int i=0;i<Q;i++){
        int l, r;
        cin >> l >> r;
        cout << num[r] - num[l-2] << "\n";
    }
    return 0;
}