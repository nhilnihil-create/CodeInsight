#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    vector<int> A(5);
    for(int i = 0; i < 5; i++){
        cin >> A[i];
    }
    int k;
    cin >> k;
    bool flg = true;
    for(int i = 0; i < 5; i++){
        for(int j = i; j < 5; j++){
            if(A[j] - A[i] > k) flg = false;
        }
    }
    if(flg) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}