#include<bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(ll i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<string> ans;
    for(int i = 0; i < s.size(); i++){
        string now = "";
        for(int j = i; j < i+k; j++){
            if(j >= s.size())break;
            now += s[j];
            ans.push_back(now);
        }
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << ans[k-1] << endl;
}
    