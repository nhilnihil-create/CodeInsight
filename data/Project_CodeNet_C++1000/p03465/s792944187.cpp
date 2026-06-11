#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

const int MAX = 4000004;

int main() {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    bitset<MAX> dp;
    dp[0] = 1;

    rep(i,n){
        dp |= (dp << a[i]);
    }

    srep(i, (sum+1)/2, sum+1){
        if(dp[i] == 1){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}


