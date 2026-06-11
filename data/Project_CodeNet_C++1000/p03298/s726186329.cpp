#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


main(){
    //制約的に半分全列挙が間に合う
    //前後半にわけて後半を反転そいつらを2つにわけることを考える
    //同じようにわけれればいい。
    int n;
    cin>>n;
    string s;
    cin>>s;
    string s1="",s2="";
    for(int i=0;i<n;i++){
        s1+=s[i];
        s2+=s[i+n];
    }
    reverse(ALL(s2));
    map<pair<string,string>,ll> m1,m2;
    for(int i=0;i<(1<<n);i++){
        string t11="",t12="",t21="",t22="";
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                t11+=s1[j];
                t21+=s2[j];
            }
            else{
                t12+=s1[j];
                t22+=s2[j];
            }
        }
        m1[make_pair(t11,t12)]++;
        m2[make_pair(t21,t22)]++;
    }
    ll ans=0;
    
    for(auto x:m1){
        /*
        前半部分について
        x.firstのペアのようにわけるのがx.secondある
        後半部分について
        x.firstのペアのようにわけるのがm2[x.first]個ある
        それらはすべて条件を満たすのでかけて加えてあげる
         */
        ans+=m2[x.first]*x.second;
    }
    cout<<ans<<endl;
    return 0;
}