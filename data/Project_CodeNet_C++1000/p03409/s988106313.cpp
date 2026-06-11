#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int N,ans;
typedef pair<int,int> P;
P R[100],B[100];
vector<P> C[100];
map<P,int> used;

int main(void){
    cin >> N;
    rep(i,N)cin >> R[i].second >> R[i].first; //firstがy座標
    rep(i,N)cin >> B[i].first >> B[i].second; //firstがx座標
    sort(B,B+N);
    sort(R,R+N,greater<P>());

    rep(i,N){
        rep(j,N){
            if(R[j].second < B[i].first && R[j].first < B[i].second){
                if(used.count(R[j])==0){
                    used[R[j]] = 1;
                    ans++;
                    break;
                }
            }
        }
    }
    /*
    rep(i,N){
        rep(j,C[i].size()){
            if(j)cout << ",";
            cout << "(" << C[i][j].first <<","<<C[i][j].second<<")";
        }
        cout << endl;
    }*/
    cout << ans << endl;
}
