#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int h,w,d;
    cin >> h >> w >> d;
    int a[h][w];
    vector<pair<int,int>> p(h*w); 
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        a[i][j]--;
        p[a[i][j]] = make_pair(i,j);
    }
    vector<vector<int>> k(d);
    for(int i=0;i<d;i++){
        int j = i,cur=0;
        k[i].push_back(cur);
        while(j+d<h*w){
            cur += abs(p[j+d].first-p[j].first)+abs(p[j+d].second-p[j].second);
            k[i].push_back(cur);
            j += d;
        }
    }
    int q;
    cin >> q;
    rep(i,q){
        int b,c;
        cin >> b >> c;
        b--;c--;
        int t = b%d;
        cout << k[t][(c-t)/d]-k[t][(b-t)/d] << endl;
    }
}