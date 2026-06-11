#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll hai[87];

    cin >> n;
    hai[0] = 2;
    hai[1] = 1;

    for(int i = 2; i<=n; i++){
        hai[i] = hai[i - 2] + hai[i - 1];
    }

    cout << hai[n] << endl;



}
