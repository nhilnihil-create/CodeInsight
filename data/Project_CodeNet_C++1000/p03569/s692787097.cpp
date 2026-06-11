    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef pair<int,int> P;
    typedef pair<ll,ll> l_l;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<ll> vl;
    typedef vector<P> vp;
    #define fi first
    #define se second
    #define rep(i,n) for(int i = 0; i < (n); ++i)
    #define rrep(i,n) for(int i = 1; i <= (n); ++i)
    #define drep(i,n) for(int i = (n)-1; i >= 0; --i)
    const int INF=1001001000;
    const int mINF=-1001001000;
    const ll LINF=1010010010010010000;
    template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
    a = b;
    return true;
    }
    return false;
    }
    template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
    a = b;
    return true;
    }
    return false;
    }
    //グリッド：（典型）dp,dfs,bfs,最短経路,その他
    int main(){
        string s;cin>>s;
        int n=s.size();
        deque<char> dq;
        rep(i,n) dq.push_back(s[i]);
        ll ans=0;
        while(dq.size()){
            char f=dq.front();
            char b=dq.back();
            //cout<<dq.size()<<endl;
            if(f==b){
                dq.pop_front();
                if(dq.size()!=0) dq.pop_back();
            }
            else if(f!=b&&f=='x'){
                dq.push_back('x');
                ans++;
            }
            else if(f!=b&&b=='x'){
                dq.push_front('x');
                ans++;
            }
            else{
                cout<<-1<<endl;
                return 0;
            }
        }
        cout<<ans<<endl;
        return 0;
    }