#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int n;
vector<int> a;
ll sum =0;
int ans =0;
ll tmp = 1e9;

int main(){
    cin >> n;
    a.resize(n);

    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    rep(i,n){
        if(abs(sum- n*a[i]) < tmp){
            tmp = abs(sum- n*a[i]);
            ans = i;
        }
    }

    dunk(ans);
}

