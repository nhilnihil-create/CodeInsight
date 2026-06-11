#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
const int mod = 1000000007;

int main(){
    int n;cin >> n;
    map<ll,ll> mp;
    for(int i=n;i>=2;i--){
        int v=i;
        for(int j=2;j*j<=i;j++){
            while(v%j==0){
                mp[j]++;
                v/=j;
                //cout << v << endl;
                //cout << mp[3] << " " << mp[2] << endl;
            }
        }
        if(v!=1) mp[v]++;
    }
    vector<ll> nums;
    for(auto p: mp){
        nums.push_back(p.second+1);
    }
    sort(nums.begin(),nums.end());
    ll num75=nums.end()-lower_bound(nums.begin(),nums.end(),75);
    ll num25=nums.end()-lower_bound(nums.begin(),nums.end(),25);
    ll num15=nums.end()-lower_bound(nums.begin(),nums.end(),15);
    ll num5=nums.end()-lower_bound(nums.begin(),nums.end(),5);
    ll num3=nums.end()-lower_bound(nums.begin(),nums.end(),3);
    if(num5<2||num3<3){
        cout << 0 << endl;
        return 0;
    }
    ll ans=num5*(num5-1)/2*(num3-2);
    ans+=num25*(num3-1);
    ans+=num15*(num5-1);
    ans+=num75;
    cout << ans << endl;
    return 0;
}