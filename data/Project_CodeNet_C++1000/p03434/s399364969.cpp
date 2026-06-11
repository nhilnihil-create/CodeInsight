#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a+n,greater<int>());
    int sa = 0, sb= 0;
    rep(i, n){
        if (i%2 == 0) sa+=a[i];
        else if (i%2 == 1) sb+=a[i];
    }
    cout << sa - sb << endl;

}