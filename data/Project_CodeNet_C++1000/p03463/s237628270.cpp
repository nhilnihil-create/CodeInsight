#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N,A,B;
    cin >> N >> A >> B;

    if(abs(A-B) % 2 != 0 || abs(A-B) == 1)cout << "Borys";
    else cout << "Alice";
    cout << endl;

    return 0;
}