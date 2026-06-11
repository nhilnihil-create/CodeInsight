#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, K;
    cin >> A >> B >> K;

    Rep (i, K) {
        if (A % 2 == 1) {
            A--;
        }

        A /= 2;
        B += A;            
        swap(A, B);
    }

    if (K % 2 == 1) swap(A, B);

    cout << A << " " << B << endl;
}