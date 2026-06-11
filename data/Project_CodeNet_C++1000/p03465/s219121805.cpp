#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 2e3 + 5;
const int maxm = 4e6 + 5;
int n , a[maxn];
bitset<maxm> dp[2];

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    cin >> n;
    int sum = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        sum += a[i];
    }
    dp[0][0] = 1;
    sum = sum / 2 + sum % 2;
    for(int i = 1 ; i <= n ; ++i){
        dp[i & 1] = dp[!(i & 1)] | (dp[!(i & 1)] << a[i]);
    }
    for( ;  ;++sum )if(dp[n & 1][sum])return cout << sum , 0;
}
