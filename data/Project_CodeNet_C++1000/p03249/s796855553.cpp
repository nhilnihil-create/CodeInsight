#include<bits/stdc++.h>
using namespace std;

int gae[100001];
vector< pair<long long, int> > p;
vector< pair<int, int> > ans;
map<long long, int> mp;
long long ll[100001];
long long su[100001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        long long x;
        scanf("%lld", &x);
        p.push_back({x, i});
        gae[i] = 1;
        mp[x] = i;
        su[i] = x;
    }
    sort(p.begin(), p.end());
    for(int i=n-1;i>=1;i--){
        int target = p[i].second;
        long long cal = p[i].first - n + gae[target] + gae[target];
        int nxt = mp[cal];
        //printf("%d %lld\n", nxt, cal);
        if(nxt == 0 || cal >= p[i].first){
            printf("-1\n");
            return 0;
        }
        gae[nxt] += gae[target];
        ll[nxt] += ll[target]; ll[nxt] += gae[target];
        ans.push_back({nxt, target});
    }
    if(ll[p[0].second] == su[p[0].second]){
        for(auto &anss: ans){
            printf("%d %d\n", anss.first, anss.second);
        }
    }else{
        printf("-1\n");
    }
}
