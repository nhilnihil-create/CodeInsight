#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    int n; cin>>n;
    vector<int> time(24);
    time[0]++;
    rep(i,n){int d; cin>>d; time[d]++;}
    int ans=-100, tmp=100;
    rep(i,(1<<12)){
        vector<int> time_=time;
        rep(j,12){
            if(i&(1<<j) && time_[j+1]>=1){
                time_[j+1]--;
                time_[23-j]++;
            }
        }
        rep(x,24){
            rep(y,24){
                if(x>=y)continue;
                if(max(time_[x],time_[y])>=2){tmp=0;break;}
                if(min(time_[x],time_[y])>0){chmin(tmp,min(y-x,24+x-y));}
            }
        }
        chmax(ans,tmp);
        tmp=100;
    }
    cout<<ans<<endl;
}
