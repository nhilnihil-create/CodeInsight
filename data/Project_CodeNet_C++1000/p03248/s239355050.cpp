#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    string s;
    cin >> s;
    if(s.back()=='1'||s.front()=='0'){
        cout << -1 << endl;
        return 0;
    }
    int n = s.size();
    string t = s.substr(0,n-1);
    if(t!=string(t.rbegin(),t.rend())){
        cout << -1 << endl;
        return 0;
    }
    vector<P> ans={P(0,1)};
    int id=1;
    for(int i=2;i<n;i++){
        if(s[i-1]=='1'){
            ans.push_back(P(id,i));
            id=i;
        }
        else{
            ans.push_back(P(id,i));
        }
    }
    rep(i,n-1){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
    return 0;
}