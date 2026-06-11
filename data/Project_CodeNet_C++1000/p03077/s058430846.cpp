#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    ll num[5];
    cin >>N;
    for(int i=0;i<5;i++){
        cin >> num[i];
    }
    ll maxOverHead =0;
    for(int i=0;i<5;i++){
        maxOverHead = max(maxOverHead,((N + num[i]-1)/num[i])-1);
    }
    cout << 5 + maxOverHead <<endl;

    return 0;
}