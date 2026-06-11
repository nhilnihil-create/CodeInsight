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
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> v;
    rep(i,n){
        int t,x,y;
        cin >> t >> x >> y;
        v.push_back(make_pair(t,make_pair(x,y)));
    }
    sort(v.begin(),v.end());
    pair<int,int> now;
    int time = 0;
    now.first = 0; now.second = 0;
    rep(i,n){
        int dis = abs(v[i].second.first - now.first) + abs(v[i].second.second - now.second);
        if(dis > v[i].first - time){
            cout << "No" << endl;
            return 0;
        }else{
            if((v[i].first - time)%2 != dis%2 ){
                cout << "No" << endl;
                return 0;
            }else{
                now.first = v[i].second.first;
                now.second = v[i].second.second;
                time = v[i].first;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}