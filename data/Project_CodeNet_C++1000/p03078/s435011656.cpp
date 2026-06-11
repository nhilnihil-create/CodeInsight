#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main(){
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y),c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];

    vector<ll> tmp;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            tmp.push_back(a[i]+b[j]);
        }
    }

    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());

    vector<ll> tmp2;
    for(int i=0;i<min(x*y,k);i++){
        for(int j=0;j<z;j++){
            tmp2.push_back(tmp[i]+c[j]);
        }
    }

    sort(tmp2.begin(),tmp2.end());
    reverse(tmp2.begin(),tmp2.end());

    rep(i,k){
        cout << tmp2[i] << endl;
    }



}