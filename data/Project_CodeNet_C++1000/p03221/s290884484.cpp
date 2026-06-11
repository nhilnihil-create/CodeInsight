#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int inum(int N,int W){
    return N/W;
}
int jnum(int N,int W){
    if((N/W)%2) return N%W;
    else return W - (N%W) - 1;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> P(m),Y(m);
    vector<vector<int>> yd(n+1);
    rep(i,m){
        cin >> P[i] >> Y[i];
        yd[P[i]].push_back(Y[i]);
    }

    rep(i,n)sort(yd[i+1].begin(),yd[i+1].end());
    rep(i,m) cout << setw(12) << setfill('0') <<  ll(P[i])*1000000 + int(lower_bound(yd[P[i]].begin(),yd[P[i]].end(),Y[i])-yd[P[i]].begin()+1) << endl;

 }
