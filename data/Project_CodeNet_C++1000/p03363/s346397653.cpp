# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
unordered_set<ll>SET;
unordered_map<ll,int>byk;
const int N=2e5+5;
int arr[N];
ll ps[N];
ll kombin(ll x){
    return x*(x-1)/2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ps[i]=ps[i-1]+arr[i];
        SET.insert(ps[i]);
        byk[ps[i]]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(ps[i]==0) ans++;
    }
    for(auto isi:SET){
        ans+=kombin(byk[isi]);
    }
    cout<<ans<<endl;

}