#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl

int main() {
    int n; cin >> n;
    vector<int> a(n+2);
    a.at(0) = 0;
    rep(i, n) cin >> a.at(i+1);
    a.push_back(0);

    ll sum = 0;
    vector<int> b;
    rep(i, n+1){
        b.push_back(a.at(i+1)-a.at(i));
        sum += abs(a.at(i)-a.at(i+1));
    }

    rep(i, n){
        cout << sum - abs(b.at(i)) - abs(b.at(i+1)) + abs(b.at(i+1)+b.at(i)) << endl;
    }


}