#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    int n,T;
    cin >> n >> T;
    int ans=10000;
    rp(i,n){
        int c,t;
        cin >> c >> t;
        if(t<=T) ans=min(ans,c);
    }
    if(ans==10000)cout << "TLE" << endl;
    else cout << ans << endl;
    return 0;
}