#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> lP;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int n,m;
    cin>>n>>m;
    vector<P> schedule;

    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        b--;
        P v=P(b,a);
        schedule.push_back(v);
    }
    //schedule (ato,mae)
    sort(schedule.begin(),schedule.end());

    int count=0;
    int t=-1;

    rep(i,m){
        if(schedule[i].second>t){
            count++;
            t=schedule[i].first;
        }
    }

    cout<<count<<endl;

}