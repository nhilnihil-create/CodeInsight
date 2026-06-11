#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
typedef pair<int,int> P;
#define mod 1000000007

int main(){
    int n,k;
    cin >> n >> k;
    if(n>=k) {
    if(n%k==0) cout << 0 <<endl;
    else cout << 1 << endl;
    }
    else cout << 1 << endl;
    return 0;
}
