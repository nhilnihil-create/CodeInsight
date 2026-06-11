#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    
    int ans  = 0;
    rep(i, n){
        if(a[i]==b[i]){
            if(a[i]!=c[i])ans++;
        }
        else if(a[i]==c[i]||b[i]==c[i])ans++;
        else ans+=2;
    }
    cout << ans << endl;
}