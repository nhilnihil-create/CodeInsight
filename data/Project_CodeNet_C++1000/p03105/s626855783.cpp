#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    cout << ((A * C <= B) ? C : B / A) << endl;
    
    return 0;
}
