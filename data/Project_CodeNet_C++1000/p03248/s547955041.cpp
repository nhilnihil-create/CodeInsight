#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]=='0'||s[n-2]=='0'||s.back()=='1'){
        cout<<-1<<"\n";
        return 0;
    }
    V<P> ans;
    int now=1;
    n--;
    bool ng=false;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            int t=1;
            while(i<n&&s[i]=='0'){
                ans.emplace_back(now,now+t);
                t++;i++;
            }
            if(i!=n&&s[i]=='1'){
                ans.emplace_back(now,now+t);
                if(s[n-i-1]=='0')ng=true;
            }
            now+=t;
        }else{
         if(s[n-i-1]=='0')ng=true;
         ans.emplace_back(now,now+1);
         now++;
        }
    }
    if(ng){
        cout<<-1<<"\n";
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].fi<<" "<<ans[i].se<<"\n";
    }
}