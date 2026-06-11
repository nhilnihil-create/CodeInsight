#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    vector<int> cnt(4);
    rep(i,0,6){
        int x;
        cin>>x;
        x--;
        cnt[x]++;
    }
    sort(all(cnt));
    if(cnt[0]==1&&cnt[1]==1&&cnt[2]==2&&cnt[3]==2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
