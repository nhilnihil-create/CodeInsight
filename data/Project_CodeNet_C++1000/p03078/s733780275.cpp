#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int cnt[3],k;
    cin >> cnt[0] >> cnt[1] >> cnt[2] >> k;
    vector<vector<ll>> cake(3);
    priority_queue<pair<ll,tuple<int,int,int>>> que;
    map<tuple<int,int,int>,bool> mp;

    for(int i = 0; i < 3; i++){
        for(ll j = 0; j < cnt[i]; j++){
            ll a; cin >> a;
            cake[i].push_back(a);
        }
    }
    for(int i = 0; i < 3; i++) sort(cake[i].begin(),cake[i].end(),greater<ll>());
    que.push({cake[0][0]+cake[1][0]+cake[2][0],make_tuple(0,0,0)});
    mp[make_tuple(0,0,0)] = true;
    for(int i = 0; i < k; i++){
        tuple<int,int,int> now = que.top().second; 
        ll sum = que.top().first;
        que.pop();
        vector<int> num(3);
        num[0] = get<0>(now);
        num[1] = get<1>(now);
        num[2] = get<2>(now);
        if(num[0] < cnt[0]-1 && !mp[make_tuple(num[0]+1,num[1],num[2])]){
            que.push({sum-cake[0][num[0]]+cake[0][num[0]+1],make_tuple(num[0]+1,num[1],num[2])});
            mp[make_tuple(num[0]+1,num[1],num[2])] = true;
        }
        if(num[1] < cnt[1]-1 && !mp[make_tuple(num[0],num[1]+1,num[2])]){
            que.push({sum-cake[1][num[1]]+cake[1][num[1]+1],make_tuple(num[0],num[1]+1,num[2])});
            mp[make_tuple(num[0],num[1]+1,num[2])] = true;
        }
        if(num[2] < cnt[2]-1 && !mp[make_tuple(num[0],num[1],num[2]+1)]){
            que.push({sum-cake[2][num[2]]+cake[2][num[2]+1],make_tuple(num[0],num[1],num[2]+1)});
            mp[make_tuple(num[0],num[1],num[2]+1)] = true;
        }
        cout << sum << endl;
    }
    return 0;
}