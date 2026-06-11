#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
using Graph = vector<vector<int>>;
typedef long long lint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<ull> ulvec;
typedef vector<double> dvec;
typedef vector<pair<int,int>> pvec;
typedef vector<pair<ll,ll>> plvec;
typedef vector<tuple<ll,ll,ll>> tvec;
typedef vector<string> svec;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    set<string> st;
    set<char> ss,tt;
    int n=s.size();
    rep(i,n)ss.insert(s[i]);
    while(!ss.empty()){
        char a=*begin(ss);
        tt.insert(a);
        ss.erase(a);
        bool ok=0;
        for(int i=0;i<n;i++){
            if(n-i>=k&&s[i]==a){
                ok=1;
                break;
            }
        }
        if(ok)break;
    }
    while(!tt.empty()){
        char b=*begin(tt);
        tt.erase(b);
        for(int i=0;i<n;i++){
            if(s[i]==b){
                string t;
                for(int j=i;j<n;j++){
                    t+=s[j];
                    st.insert(t);
                    if(j-i+1>=k)break;
                }
            }
        }
        if(st.size()>=k)break;
    }
    while(k>1){
        string u=*begin(st);
        st.erase(u);
        k--;
    }
    cout<<*begin(st)<<endl;
}