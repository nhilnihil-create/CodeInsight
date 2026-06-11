#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define lint long long

int main(){
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a;
    rep(i, n){
        int x; cin >> x;
        a.push_back(x);
    }
    if(n==1) cout << abs(a[0]-w) << endl;
    else cout << max(abs(a[n-1]-w), abs(a[n-1]-a[n-2])) << endl;
}