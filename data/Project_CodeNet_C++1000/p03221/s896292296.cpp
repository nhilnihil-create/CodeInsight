#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<P> data(m);
    vector<vector<int> > num(n);

    rep(i,m){
        int p,y; cin >> p >> y;
        p--;
        data[i].first=p;
        data[i].second=y;
        num[p].push_back(y);
    }
    
    rep(i,n){
        sort(all(num[i]));
    }

    rep(i,m){
        int p,y;
        p=data[i].first;
        y=data[i].second;
        auto it=lower_bound(all(num[p]),y);
        int ans=it-num[p].begin();
        ans++;
        p++;
        int tmpp=p;
        int tmpans=ans;
        int pmod=0;
        int ansmod=0;
        while(tmpp){
            tmpp/=10;
            pmod++;
        }
        while(tmpans){
            tmpans/=10;
            ansmod++;
        }
        rep(j,6-pmod) printf("0");
        printf("%d",p);
        rep(j,6-ansmod) printf("0");
        printf("%d",ans);
        puts("");
    }
    return 0;
}
