#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
int n,q;
bool check1(int mid, vector <pair<char,char>> & magic, string &s){
    if(mid <-1) return true;
    if(mid >=n) return false;
    //cout<<q<<endl;
    rep(i,q){
        //cout<<mid<<' '<<magic[i].F<<i<<endl;
        if(s[mid]==magic[i].F) mid += (magic[i].S == 'R') ? 1:-1;
        if(mid == -1) {return true; }
        if(mid == n) {return false;}
    }
    return false;
}
bool check2(int mid, vector <pair<char,char>> & magic, string &s){
    if(mid <0||mid>=n) return true;
    rep(i,q){
        if(s[mid]==magic[i].F) mid += (magic[i].S == 'R') ? 1:-1;
        if(mid == n) return true; 
        if(mid == -1) return false;
    }
    return false;
}
signed main(void){
    cin>>n>>q;
    
    string s; cin>>s;
    vector <pair<char,char>> magic(q);
    rep(i,q){
        cin>>magic[i].F>>magic[i].S;
    }
    /// disapper in leftside
    int l = -1, r = 200010;
    
    while(abs(l-r)>1){
        int mid = (l+r)/2;
        if(check1(mid, magic, s)) {l = mid; }
        else {r = mid;}
    }
    int ans1 = l;
    //cout<<ans1<<' '<<'*'<<endl;
    r = 200010;
    // rightside
    while(abs(l-r)>1){
        int mid = (l+r)/2;
        if(check2(mid, magic, s)) { r = mid;}
        else l = mid;
    }
    
    int ans2 = l;
    
    cout<<ans2-ans1<<endl;
}
