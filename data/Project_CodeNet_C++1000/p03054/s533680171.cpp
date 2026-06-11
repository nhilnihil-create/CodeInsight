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

void solve(int ca){
    int H,W,N; cin>>H>>W>>N;
    int sy,sx; cin>>sy>>sx;
    --sy; --sx;
    string S,T; cin>>S>>T;
    vector<int> ty(N,0),tx(N,0),ay(N,0),ax(N,0);
    for (int i = 0; i < N; ++i) {
        switch (S[i]){
            case 'L': tx[i]=-1;
                break;
            case 'R': tx[i]=1;
                break;
            case 'U': ty[i]=-1;
                break;
            case 'D': ty[i]=1;
                break;
        }
        switch (T[i]){
            case 'L': ax[i]=-1;
                break;
            case 'R': ax[i]=1;
                break;
            case 'U': ay[i]=-1;
                break;
            case 'D': ay[i]=1;
                break;
        }
    }

    int maxiy=sy,miniy=sy,maxix=sx,minix=sx;
    for (int i = 0; i < N; ++i) {
        //cout<<maxiy<<" "<<miniy<<" "<<maxix<<" "<<miniy<<endl;
        //takahashi
        if(ty[i]==1) maxiy++;
        if(ty[i]==-1) miniy--;
        if(tx[i]==1) maxix++;
        if(tx[i]==-1) minix--;
        if(maxiy>=H||miniy<0||maxix>=W||minix<0){
            cout<<"NO"<<endl;
            return;
        }

        //aoki
        if(ay[i]==1) miniy=min(miniy+1,H-1);
        if(ay[i]==-1) maxiy=max(maxiy-1,0);
        if(ax[i]==1) minix=min(minix+1,W-1);
        if(ax[i]==-1) maxix=max(maxix-1,0);
        //cout<<maxiy<<" "<<miniy<<" "<<maxix<<" "<<miniy<<endl;
        //cout<<"----"<<endl;
    }
    cout<<"YES"<<endl;



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
