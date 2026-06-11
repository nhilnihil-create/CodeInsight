#include <bits/stdc++.h>
using namespace std;
#define LIMIT 1000000000000000000
typedef long long ll;

int main(void){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if (abs(a-b) > LIMIT){
        cout << "Unfair" << endl;
    } else{
        cout << (k%2==1 ? -(a-b) : a-b) << endl;
    }
    return 0;
}