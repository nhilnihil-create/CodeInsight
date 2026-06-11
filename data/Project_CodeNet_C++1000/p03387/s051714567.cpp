#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    ll maxx = max(A, max(B, C));
    vector<ll> dif(3);
    dif[0] = maxx - A;
    dif[1] = maxx - B;
    dif[2] = maxx - C;
    sort(dif.begin(), dif.end(), greater<ll>());
    ll cnt = 0;
    cnt += dif[1];
    cnt += (dif[0] - dif[1]) / 2;
    vector<ll> ch(3);
    ch[0] = A;
    ch[1] = B; 
    ch[2] = C;
    sort(ch.begin(), ch.end());
    if(ch[0]%2!=ch[1]%2){
      cout << cnt + 2 << endl;
    }
    else cout << cnt << endl;
    return 0;
}