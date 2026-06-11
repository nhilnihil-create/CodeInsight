#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(n) cout << n << endl
using namespace std;
using ll = long long;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int A, B;
    cin >> A >> B;

    print(((B % A) ? B - A : A + B));

    return 0;
}
