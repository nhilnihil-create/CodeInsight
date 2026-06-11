#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

struct pos{
    int mx, mn;
};

int main(){
    int h,w,n;cin >> h >> w >> n;
    int x,y;cin >> y >> x;
    --x;--y;
    string s,t;cin >> s >> t;
    vector<int> dire(4);
    dire[0] = y;
    dire[1] = x;
    dire[2] = y;
    dire[3] = x;
    // dire[i][0] = max
    // dire[i][1] = min
    // 0 : up / 1 : right / 2 : down / 3 : left 
    rep(i,n){
        // s
        if(s[i]=='U'){
            --dire[0];
        }else if(s[i]=='R'){
            ++dire[1];
        }else if(s[i]=='D'){
            ++dire[2];
        }else if(s[i]=='L'){
            --dire[3];
        }

        if(dire[0]<0 || dire[1]>=w || dire[2]>=h || dire[3]<0){
            cout << "NO" << endl;
            return 0;
        }
        
        // t
        if(t[i]=='U'){
            dire[2] = max(0, dire[2] -1);
        }else if(t[i]=='R'){
            dire[3] = min(w-1, dire[3] +1);
        }else if(t[i]=='D'){
            dire[0] = min(h-1, dire[0] +1);
        }else if(t[i]=='L'){
            dire[1] = max(0, dire[1] -1);
        }
    }
    cout << "YES" << endl;
}