#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define rep11(i, n) for (int i = 1; i < (int)(n); ++i)
#define repo(i, o, n) for (int i = o; i < (int)(n); ++i)
#define repm(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1002000007
#define INF LONG_LONG_MAX

typedef pair<int, int> P;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,n){
        cin>>v[i];
    }
    vector<P> ki(100001);
    vector<P> gu(100001);
    rep(i,100001){
        ki[i].second=i;
        gu[i].second=i;
    }
    int ki_co=0;
    int gu_co=0;
    for(int i=0; i<n; i+=2){
        ki[v[i]].first-=1;
        ki_co++;
    }
    for(int i=1; i<n; i+=2){
        gu[v[i]].first-=1;
        gu_co++;
    }
    sort(ki.begin(),ki.end());
    sort(gu.begin(),gu.end());
    if(ki[0].first==gu[0].first && ki[0].second==gu[0].second){
        if(ki[1].first<=gu[1].first){
            cout<<ki_co+ki[1].first+gu_co+gu[0].first<<endl;
        }
        else{
            cout<<ki_co+ki[0].first+gu_co+gu[1].first<<endl;
        }
    }
    else if(ki[0].first!=gu[0].first && ki[0].second==gu[0].second){
        if(ki[0].first<gu[0].first){
             cout<<ki_co+ki[0].first+gu_co+gu[1].first<<endl;
        }
        else{
            cout<<ki_co+ki[1].first+gu_co+gu[0].first<<endl;
        }
    }
    else{
        cout<<ki_co+ki[0].first+gu_co+gu[0].first<<endl;
    }

}
