#include <bits/stdc++.h>
//C
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
        ///memset   ///regular use
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) { return a * b / gcd(a, b);}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans = 0;
    set<int> st[n+1];//switch i affects which bulbs

    for(int i =0; i<m; i++){
        int k, swt;
        cin>>k;
        for(int j =0; j<k; j++){
            cin>>swt;
            swt--;
            st[swt].insert(i);//switch swt, affects bulb i
        }
    }
    int parity[m];
    for(int i =0; i<m; i++){
        cin>>parity[i];
    }

    for(int i =0; i<(1<<(n)); i++){
        int cnt[m];
        for(int j =0; j<m; j++){
            cnt[j] = 0;
        }
        for(int j =0; j<=n; j++){
            if(((1<<j)&i)){//switch is used in this combo
                for(auto it = st[j].begin(); it!=st[j].end(); it++){
                    cnt[*it]++;
                    //cout<<"iter " <<*it<<"\n";
                }
            }
        }
        bool ok = true;
        for(int j =0; j<m; j++){
            if(cnt[j]%2!= parity[j]){
                //cout<<"mask "<<i<<"\n";
                //cout<<j<<" " << cnt[j]<<"\n";
                ok = false;
                break;
            }
        }
        if(ok){
            ans++;
        }
    }
    cout<<ans<<"\n";
}
