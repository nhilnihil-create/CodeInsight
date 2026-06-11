#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    vector<int> x(5);
    rep(i, 5) cin >> x[i];
    int k;
    cin >> k;

    rep(i, 5) rep (j, 5) {
        if (abs(x[i] - x[j]) > k) {
            println(":(");
            return 0;
        }
    }
    
    println("Yay!");
    return 0;
}