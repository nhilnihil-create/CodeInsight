#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,n;cin >> h >> w >> n;
    int sh,sw;cin >> sh >> sw;
    sh--,sw--;
    string s,t;cin >> s >> t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    int l=0,r=w-1,u=0,d=h-1;
    if(s[0]=='L'){
        l++;
    }
    if(s[0]=='R'){
        r--;
    }
    if(s[0]=='U'){
        u++;
    }
    if(s[0]=='D'){
        d--;
    }
    for(int i=1;i<n;i++){
        if(t[i]=='L'){
            r=min(w-1,r+1);
        }
        if(t[i]=='R'){
            l=max(0,l-1);
        }
        if(t[i]=='U'){
            d=min(h-1,d+1);
        }
        if(t[i]=='D'){
            u=max(0,u-1);
        }
        if(s[i]=='L'){
            l++;
        }
        if(s[i]=='R'){
            r--;
        }
        if(s[i]=='U'){
            u++;
        }
        if(s[i]=='D'){
            d--;
        }
        if(l>r||u>d){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(l<=sw&&sw<=r&&u<=sh&&sh<=d){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}