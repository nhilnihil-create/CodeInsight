#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll  A,B,X;
    cin >> A >>B>>X;
    if(A>X || A+B<X){
        cout <<"NO" << endl;
        return 0;
    }
    cout <<"YES" << endl;


    return 0;
}