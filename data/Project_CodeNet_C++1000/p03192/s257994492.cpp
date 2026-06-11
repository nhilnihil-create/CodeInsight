#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int ans = 0;
    if (N % 10 == 2) ans++;
    N /= 10;
    if (N % 10 == 2) ans++;
    N /= 10;
    if (N % 10 == 2) ans++;
    N /= 10;
    if (N % 10 == 2) ans++;
    
    cout << ans << endl;
}