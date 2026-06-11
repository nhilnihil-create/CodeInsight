#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e5+6;
const int M = 998244353;
const int inf = 1e9;
ll iv[N],f1[N],f2[N];
ll nck(int n, int k) {
	return f1[n]*f2[k]%M*f2[n-k]%M;
}
int cnt(int x){
    int ret = 0;
    while(x){
        ret+=x%10;
        x/=10;
    }
    return ret;
}
void solve(){
    int n;
    cin>>n;
    int mn = inf;
    for(int i=1;i<n;i++){
        mn = min(mn,cnt(i)+cnt(n-i));
    }
    cout<<mn<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
