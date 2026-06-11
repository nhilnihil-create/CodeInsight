//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};



int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<int> a(0);
    int f=s[0]-'0';
    int cnt=0;
    if(!f) a.emplace_back(0);
    rep(i,n){
        if(f==(s[i]-'0')){
            cnt ++;
        }
        else{
            if(!f) cnt=-cnt;
            a.emplace_back(cnt);
            cnt=1;
            f =s[i]-'0';
        }
    }
    if(!f) cnt=-cnt;
    a.emplace_back(cnt);
    if(!f) a.emplace_back(0);
    int ans=0;
    cnt=0;
    n=a.size();
    int ss=0,t=0;
    rep(i,n){
        if(a[i]<0) cnt ++;
        if(cnt>k) break;
        ans +=abs(a[i]);
        t=i;
    }
    int now=ans;
    while(t+2<n){
        now =now-abs(a[ss])+a[ss+1]-a[t+1]+a[t+2];
        ss +=2;
        t +=2;
        ans=max(ans,now);
    }
    cout<<ans<<endl;
}