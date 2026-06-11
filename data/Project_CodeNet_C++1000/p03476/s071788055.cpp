#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

const int N = 100000;
vector<bool> isp(N + 1, true);

void sieve(){
    isp[0] = false;
    isp[1] = false;
    for (int i = 2; i < N; i++){
        if(isp[i]){
            for (int j = 2; i * j <= N; j++){
                isp[i * j] = false;
            }
        }
    }
}

int main(){
    int q;
    cin >> q;
    sieve();
    vector<int> num(100001,0);
    for (int i = 1; i < 100001; ++i)
    {
        if(i%2==0)
            continue;
        if (isp[i] && isp[(i + 1) / 2])
            num[i]++;
    }
    rep(i, 100001) num[i + 1] += num[i];
    int l, r;
    rep(i, q)
    {
        cin >> l >> r;
        cout << num[r] - num[l-1] << endl;
    }
    return 0;
}