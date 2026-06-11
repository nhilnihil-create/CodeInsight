#include <bits/stdc++.h>
using namespace std;



#define rep(i, x)   for (__typeof(x) i = 0; i < x; i++)
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define repi(i, x)  for (__typeof(x) i = x-1; i >= 0; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
typedef vector<vector<int>> vvi;
typedef vector<ll>     vl;
typedef vector<vector<ll>> vvl;
const int infi = numeric_limits<int>::max();
const ll infl = numeric_limits<ll>::max();

const   double         eps = 0;
const   int            ms  = 0;

int N;
ll ans=0;
unordered_map<string, ll> ls_n;

string l, r;
void fl(int i, string s0, string s1){
    if(i == N){
        string q = s0 + " " + s1;
        //debug(q);
        ls_n[q]==0?ls_n[q]=1:ls_n[q]++;
        return;
    }
    fl(i+1, s0+l[i], s1);
    fl(i+1, s0, l[i]+s1);
}

void fr(int i, string s0, string s1){
    if(i == N ){
        string q = s0 + " " + s1;
        //debug(q);
        //debug(ls_n[q]);
        ans+=ls_n[s0+" "+s1];
        return;
    }
    fr(i+1, s0+r[N-i-1], s1);
    fr(i+1, s0, r[N-i-1]+s1);
}

int main(){
    string s;
    
    cin >> N;
    cin >> s;
    debug(s);
    l = s.substr(0, N);
    r = s.substr(N, 2*N); 
    debug(l);
    debug(r);
    fl(0, "","");
    fr(0, "","");
    cout << ans << endl;
    
    
    return 0;
}