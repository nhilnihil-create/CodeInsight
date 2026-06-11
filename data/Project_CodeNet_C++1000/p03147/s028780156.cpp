//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
    int n;
    cin >> n;
    vector<int>h(n);
    for(int i=0;i<n;i++)cin >> h[i];
    vector<int>f(n,0);
    int ans=0;
    while(1){
        int flag=0;
        for(int i=0;i<n;i++){
            if(h[i]!=f[i]){
                f[i]++;
                flag=1;
            }
            else if(h[i]==f[i] && flag==1){
                ans++;
                flag=0;
            }
        }
        if(flag==1)ans++;
        bool g=true;
        for(int i=0;i<n;i++){
            if(h[i]!=f[i])break;
            if(i==n-1)g=false;
        }
        if(g==false)break;
    }
    cout << ans << endl;

}

int main(){
    solve();
    return 0;
}


