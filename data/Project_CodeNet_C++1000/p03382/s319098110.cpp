#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD = 1e9 + 7;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll ma=a[n-1],low,high;
    if(ma%2==0) low=high=ma/2;
    else{
        low=ma/2;
        high=ma/2+1;
    }
    ll dif=ma,idx;
    for(int i=0;i<n-1;i++){
        if(a[i]<=low){
            if(low-a[i]<=dif){
                dif=low-a[i];
                idx=i;
            }
        }
        else{
            if(a[i]-high<=dif){
                dif=a[i]-high;
                idx=i;
            }
        }
    }
    cout<<ma<<" "<<a[idx]<<endl;
}
