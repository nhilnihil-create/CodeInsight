#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,k; cin >> n >> k;
    if((n+1)/2>=k)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}