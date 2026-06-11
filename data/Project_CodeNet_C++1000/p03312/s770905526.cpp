#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) {
        cin >> a.at(i);
        if (i==0) b.at(i)=a.at(i);
        else b.at(i)=b.at(i-1)+a.at(i);
        }
    int k=1,kk=1;
    ll ans=INF;
    ll t,tt;
    for (int i=1;i<n-2;i++){
        while (true){
           t=abs(b.at(k-1)-(b.at(i)-b.at(k-1)));
           if (t<abs(b.at(k)-(b.at(i)-b.at(k)))) break;
           k++;   
        }
        while (true){
            tt=abs(b.at(i+kk)-b.at(i)-(b.at(n-1)-b.at(i+kk)));
            if (tt<abs(b.at(i+kk+1)-b.at(i)-(b.at(n-1)-b.at(i+kk+1)))) break;
            kk++;
        }
        ll p=max(b.at(k-1),(b.at(i)-b.at(k-1)));
        p=max(p,b.at(i+kk)-b.at(i));
        p=max(p,b.at(n-1)-b.at(i+kk));
        ll q=min(b.at(k-1),(b.at(i)-b.at(k-1)));
        q=min(q,b.at(i+kk)-b.at(i));
        q=min(q,b.at(n-1)-b.at(i+kk));
        ans=min(ans,p-q);
        //cout << k << " " << kk << " " << ans << endl;
        kk--;
    }
    cout << ans << endl;
}