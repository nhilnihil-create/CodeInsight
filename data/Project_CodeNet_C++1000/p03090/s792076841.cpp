// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30);
const int INF = (1LL << 60);
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n;
    cin>>n;
    if(n==3){
        cout<<"2 1 3 2 3"<<endl;
    }
    else if(n%2==0){
        int memo=n+1;
        int cnt=0;
        rep(i,n-1){
            rep(j,n){
                if(i+1+j+1==memo||i>=j) continue;
                cnt++;
            }
        }
        cout<<cnt<<endl;
        rep(i,n-1){
            rep(j,n){
                if(i+1+j+1==memo||i>=j) continue;
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
    else{
        // exit(1);
        pvec a(n/2+1);
        for(int i=0;i<n/2;i++){
            a[i]=P(i+1,n-(i+1));
            // cout<<i+1<<n-i-1<<endl;
        }
        a[n/2]=P(n,-1);
        int x=a.size();
        int cnt=0;
        for(int i=0;i<x-1;i++){
            for(int j=i+1;j<x;j++){
                //cout<<a[i].fs<<" "<<a[j].fs<<endl;
                //cout<<a[i].sc<<" "<<a[j].fs<<endl;
                cnt+=2;
                if(j==x-1) continue;
                //cout<<a[i].fs<<" "<<a[j].sc<<endl;
                //cout<<a[i].sc<<" "<<a[j].sc<<endl;
                cnt+=2;
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<x-1;i++){
            for(int j=i+1;j<x;j++){
                cout<<a[i].fs<<" "<<a[j].fs<<endl;
                cout<<a[i].sc<<" "<<a[j].fs<<endl;
                //cnt+=2;
                if(j==x-1) continue;
                cout<<a[i].fs<<" "<<a[j].sc<<endl;
                cout<<a[i].sc<<" "<<a[j].sc<<endl;
                //cnt+=2;
            }
        }
    }

    
}