//苦手 解説AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0;
    //負の数が奇数かのflag
    bool flag = false;
    rep(i,n) {
        int input;
        cin >> input;
        if(input<0) flag = 1-flag;
        a[i] = abs(input);
        sum+=abs(input);
    }
    sort(a.begin(),a.end());
    if(!flag)
        cout << sum << endl;
    else
        cout << sum-2*a[0] << endl;
	return 0;
}