#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n;cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    queue<ll> q;
    ll sum=0;
    ll ans=0;
    ll cnt=0;
    ll checker=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        q.push(a[i]);
        cnt++;
        checker=checker^a[i];
        while(checker!=sum){
            sum-=q.front();
            checker=checker^q.front();
            q.pop();
            cnt--;
            //cout << "i" << i << "q.sz" << q.size() << endl;
        }
        ans+=cnt;
    }
    cout << ans << endl;
    return 0;
}