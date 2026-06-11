#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vi2 = vector<vector<int>>;
#define MP(a,b) make_pair((a),(b))
#define MT(...) make_tuple(__VA_ARGS__)

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl;

#define DCOUT(x,n) cout << fixed << setprecision(n) << (x) << endl;

#define sz(x) (int)(x).size()
#define HOGE cout << "hoge" << endl;

template<typename T>inline istream& operator>>(istream&i,vector<T>&v)
{REP(j,sz(v))i>>v[j];return i;}

const int INF = 1e9;


int main(){
    ll N;
    cin >> N;
    ll m=0, a=0, r=0, c=0, h=0;
    string S;
    
    REP(i,N){
        cin >> S;
        if(S[0]=='M') m++;
        if(S[0]=='A') a++;
        if(S[0]=='R') r++;
        if(S[0]=='C') c++;
        if(S[0]=='H') h++;
    }
    
    ll D[5] = {m,a,r,c,h};
    int C_1 [10]= {0,0,0,0,0,0,1,1,1,2};
    int C_2 [10]= {1,1,1,2,2,3,2,2,3,3};
    int C_3 [10]= {2,3,4,3,4,4,3,4,4,4};
    
    ll ans=0;
    REP(i,10){
        ans += D[C_1[i]]*D[C_2[i]]*D[C_3[i]];
    }
    cout << ans << endl;
}
