#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main(){
    int h,w,n,sr,sc;
    cin>>h>>w>>n>>sr>>sc;
    sr--;sc--;
    
    string s,t;
    cin>>s>>t;
    
    int down=0,up=h;
    if(s[n-1]=='U') down++;
    if(s[n-1]=='D') up--;
    rrep(i,n-1){
        if(t[i]=='U') up=min(up+1,h);
        if(t[i]=='D') down=max(down-1,0);
        
        if(s[i]=='U') down++;
        if(s[i]=='D') up--;
        
        if(down>=up){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(down>sr || sr>=up){
        cout<<"NO"<<endl;
        return 0;
    }
    
    int left=0,right=w;
    if(s[n-1]=='L') left++;
    if(s[n-1]=='R') right--;
    rrep(i,n-1){
        if(t[i]=='L') right=min(right+1,w);
        if(t[i]=='R') left=max(left-1,0);
        
        if(s[i]=='L') left++;
        if(s[i]=='R') right--;
        
        if(left>=right){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(left>sc || sc>=right){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
}
