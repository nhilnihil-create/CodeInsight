#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100005
#define INF 1000000005
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 998244353;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>m;
    REP(i,n){
        cin>>a[i];
        m[a[i]]++;
    }
    sort(ALL(a));
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int t=1;
        if(m[a[i]]<=0)continue;
        m[a[i]]--;
        while(!(t<=a[i]&&a[i]<2*t)){
            t*=2;
        }
        t*=2;
        bool f=binary_search(ALL(a),t-a[i]);
        if(f&&m[t-a[i]]>0){
            ans+=1;
            m[t-a[i]]--;
        }
    }
    OUT(ans);
    return 0;
}