#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v1(100010),v2(100010);
    rep(i,100010){
        v1[i].second=i+1;
        v2[i].second=i+1;
    }
    rep(i,n){
        int x;
        cin >> x;
        if(i%2==0){
            v1[x].first++;
        }else{
            v2[x].first++;
        }
    }
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());

    pair<int,int> pii1[2],pii2[2];
    pii1[0].first = v1[0].second;
    pii1[0].second =v1[0].first;
    pii1[1].first =v1[1].second;
    pii1[1].second =v1[1].first;

    pii2[0].first = v2[0].second;
    pii2[0].second =v2[0].first;
    pii2[1].first =v2[1].second;
    pii2[1].second =v2[1].first;

    if(pii1[0].first!=pii2[0].first){
        cout<<n-pii1[0].second-pii2[0].second<<endl;
        return 0;
    }

    int ans1 = n - pii1[0].second - pii2[1].second;
    int ans2 = n - pii1[1].second - pii2[0].second;
    cout<< min(ans1,ans2)<<endl;
    return 0;
}