#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

int main() {
    int n; cin >> n;
    vector<int> a,b;
    for(int i = 0;i < n;i++){
        int z; cin >> z;
        a.push_back(z);b.push_back(z);
    }
    sort(b.begin(),b.end());
    
    int right = b[n / 2 - 1];
    int left = b[n / 2];
    for(int i = 0;i < n;i++){
        if(a[i] < b[n/2]){
            cout << left << endl;
        }else{
            cout << right << endl;
        }
    }
}
