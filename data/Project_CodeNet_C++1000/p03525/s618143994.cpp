#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
//const ll MOD=(ll)998244353;
const ll INF=(ll)1e18+10;
const double PI = 2.0*acos(0);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int calc(const vector<bool>& exist){
    int ans = 340;
    for (int i = 0; i < 24; ++i) {
        for (int j = i+1; j < 24; ++j) {
            if(exist[i]&&exist[j]){
                //cout<<i<<" "<<j<<endl;
                ans=min(ans,min(j-i,i+24-j));
            }
        }
    }
    return ans;
}

void solve(int ca){
    int N; cin>>N;
    int cnt[13]={0};
    cnt[0]++;
    for (int i = 0; i < N; ++i) {
        int d; cin>>d;
        cnt[d]++;
    }

    vector<bool> exist(24,false);
    
    exist[0]=true;

    if(cnt[0]>=2||cnt[12]>=2){
        cout<<0<<endl;
        return;
    }

    vector<int> select;

    for(int i=1;i<=12;++i){
        if(cnt[i]>2){
            cout<<0<<endl;
            return;
        }
        if(cnt[i]==2){
            exist[i]= true;
            exist[24-i]= true;
        }
        if(cnt[i]==1) select.push_back(i);
    }

    int ans=0;
    if(select.empty()){
        cout<<calc(exist)<<endl;
        return;
    }
    for (int bit = 0; bit < (1<<select.size()); ++bit) {
        vector<bool> ex_cp=exist;
        for (int i = 0; i < select.size(); ++i) {
            if((bit>>i)&1){
                ex_cp[select[i]]= true;
            }else{
                ex_cp[24-select[i]]=true;
            }
        }
        /*
        for(auto i:ex_cp){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<calc(ex_cp)<<endl;
         */
        ans=max(ans,calc(ex_cp));
    }
    cout<<ans<<endl;

}

//#define MULTI
int main() {
#ifdef MULTI
    int N; cin>>N;
    for (int i = 0; i < N; ++i) {
        solve(i+1);
    }
#else
    solve(0);
#endif
    return 0;
}
