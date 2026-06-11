#include<bits/stdc++.h>                                                                                               
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
#define mk_p(a,b)   make_pair((a),(b))
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;

vector<pair<double,int> > a;
signed main(){
    int n;
    cin >> n;
    double avg = 0,x;
    rep(i,n){
        cin >> x;
        avg += x;
        a.push_back(mk_p(x,i));
    }   
    avg /= n;
    rep(i,n){
        a[i].first = abs(avg - a[i].first);
    }   
    sort(all(a));
    cout << a[0].second << '\n';
    return 0;
}
