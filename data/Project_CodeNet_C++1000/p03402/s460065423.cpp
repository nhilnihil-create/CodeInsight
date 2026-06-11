#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
//typedef tuple<ll, ll, ll> T;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    string s[100];
    REP(i,100) REP(j,100){
        if(i<50) s[i].push_back('.');
        else s[i].push_back('#');
    }
    int cnt=0;
    for(int i=0;i<50;i+=2){
        if(cnt==b-1) break;
        for(int j=0;j<100;j+=2){
            if(cnt==b-1) break;
            s[i][j] = '#';
            cnt++;
        }
    }
    cnt=0;
    for(int i=51;i<100;i+=2){
        if(cnt==a-1) break;
        for(int j=0;j<100;j+=2){
            if(cnt==a-1) break;
            s[i][j]='.';
            cnt++;
        }
    }
    cout<<100<<" "<<100<<endl;
    REP(i,100) cout<<s[i]<<endl;
}
