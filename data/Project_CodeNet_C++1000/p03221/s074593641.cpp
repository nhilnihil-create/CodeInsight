#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <utility>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<int> vec[100010];

int main(){
    int n,m;
    cin >> n >> m;
    vector<pii> vpii(m);
    map<pii,int> mp;

    int p,y;
    
    rep(i,m){
        cin >> p >> y;
        vpii[i] = make_pair(p,y);
        vec[p].push_back(y);
    }

    reps(i,1,n+1){
        sort(vec[i].begin(),vec[i].end(),less<int>() );
        
        rep(j,vec[i].size()){
            mp[make_pair(i,vec[i][j])] = j+1;
        }
    }

    rep(i,m){
        p = vpii[i].first;
        y = vpii[i].second;
        int order = mp[make_pair(p,y)];
        printf("%06d%06d\n",p,order);
    }    

    return 0;
}
