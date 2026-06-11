#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;

int main() {
    int n,k; cin >> n >> k;
    map<int,int> m;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        auto result = m.find(x);
        if(result == m.end()){
            m.insert(make_pair(x,1));
        }else{
            result->second+=1;
        }
    }
    vector<int> vec;
    for(auto a:m){
        vec.push_back(a.second);
    }
    sort(vec.begin(),vec.end());
    int cnt = vec.size();
    int ans = 0,i = 0;
    while(cnt > k){
        ans+=vec[i];i++;
        cnt--;
    }
    cout << ans;
}


