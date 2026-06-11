#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<ll,pair<ll,ll>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main(){
    string s;
    int n, k, cnt0 = 0, cnt1 = 0;
    cin >> n >> k >> s;
    vector<int> a, b;
    rep(i, n){
        if(s[i] == '0')cnt0++;
        if(s[i] == '1'){
            if(!i);  
            else if(s[i-1] == '0')a.push_back(cnt0); 
            cnt0 = 0;
        }
        if(s[i] == '1')cnt1++;
        if(s[i] == '0'){
            if(!i);
            else if(s[i-1] == '1')b.push_back(cnt1);
            cnt1 = 0;
        }
    }
    if(s[0] == '0')b.insert(b.begin(), 0);
    if(s[n-1] == '1'){
        b.push_back(cnt1);
    }else{
        b.push_back(0);
        a.push_back(cnt0);
    }
    vector<int> vec; vec.push_back(b[0]);
    rep(i, b.size()-1){
        vec.push_back(a[i]);
        vec.push_back(b[i+1]);
    }
    int num = 0, sum = 0, ans = 0;
    rep(i, min((int)vec.size(), 2*k+1))sum += vec[i];
    ans = sum;
    for(int i = 2*k+2; i < vec.size(); i+=2){
        sum += vec[i] + vec[i-1];
        sum -= vec[i-2*k-2] + vec[i-2*k-1];
        chmax(ans, sum);
    }
    cout << ans << endl;
}