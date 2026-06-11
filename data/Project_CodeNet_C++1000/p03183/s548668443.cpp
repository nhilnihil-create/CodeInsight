/*
Saurabh Joshi
IIIT Jabalpur
*/
#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define endl "\n"
#define eps 0.00000001
LL pow(LL a,LL b,LL m){ a%=m;LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
int w[1001], s[1001], v[1001];
LL dp[1001][10005];
int n;
LL f(int pos,int w) {
    if(pos == n + 1)
        return 0;
    if(dp[pos][w] != -1)
        return dp[pos][w];
    LL ans = f(pos + 1 , w);
    if(w <= s[pos]) {
        ans = max(ans , f(pos + 1 , min(10001 , w + ::w[pos])) + v[pos]);
    }
    return dp[pos][w] = ans;
}
int main()	{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> s[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(s[i] + w[i] > s[j] + w[j]) {
                swap(w[i] , w[j]);
                swap(s[i] , s[j]);
                swap(v[i] , v[j]);
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1 , 0);
    
}