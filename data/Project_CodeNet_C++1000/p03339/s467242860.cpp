#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    int n;string s;cin >>n>>s;
    
    vi west(n), east(n);
    
    for(int i=0; i<n; i++){
        if(i)west[i] += west[i-1];
        if(s[i]=='W')west[i]++;
    }
    
    for(int i=n-1; i>=0; i--){
        if(i!=n-1)east[i] += east[i+1];
        if(s[i]=='E')east[i]++;
    }
    
    int ans = 300000;
    for(int i=0; i<n; i++){
        int c;
        if(!i)
            c = east[1];
        else if(i==n-1){
            c = west[n-2];
        }
        else{
            c = east[i+1] + west[i-1];
        }
        
        ans = min(ans, c);
    }
    
    cout << ans << endl;
    
    return 0;
}