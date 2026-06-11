#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;


int main(void) {
    ll N;
    cin >> N;
    vector<ll> ans;
    ll i;
    
    if(N==3) {
        pt(2<<" "<<5<<" "<<63);
        return 0;
    }else if(N==4) {
        pt(2<<" "<<5<<" "<<20<<" "<<63);
        return 0;
    }else if(N==5) {
        pt(3<<" "<<4<<" "<<9<<" "<<10<<" "<<16);
        return 0;
    }
    
    for(i=3; ans.size()<N-2 && i<=30000; i+=3) {
        ans.pb(i);
    }

    if(ans.size()==N-2) {
        if((N-2)%4==0 || (N-2)%4==3) {
            ans.pb(2);
            ans.pb(4);
        }else if((N-2)%4==1) {
            ans.erase(ans.begin()+N-3);
            ans.pb(4);
            ans.pb(10);
            ans.pb(16);
        }else if((N-2)%4==2) {
            ans.erase(ans.begin()+N-4);
            ans.pb(4);
            ans.pb(10);
            ans.pb(16);
        }
    }else {
        
        if((N-ans.size())%2==0) {
            for(i=2; ans.size()<N; i+=2) {
                if(i%3==0) continue;
                ans.pb(i);
            }
        }else {
            ans.erase(ans.begin()+9999);
            for(i=2; ans.size()<N; i+=2) {
                if(i%3==0) continue;
                ans.pb(i);
            }
        }
    }
    
    //sort(ans.begin(), ans.end());
    for(i=0; i<N; i++)
        cout << ans[i] << " ";
    cout << endl;
}





