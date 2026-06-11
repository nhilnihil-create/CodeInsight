#include <bits/stdc++.h>

using namespace std;

const int N = 8005;
const int maxn = 2*N+1;

int x,y,f[3][3][maxn],tt[3];
string t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
  //  freopen("in.txt","r",stdin);
    cin>>t;
    cin>>x>>y;
    f[0][1][N] = 1; f[1][1][N] = 1;
    int i =0;
    int id = 0,time=0;
    while (i<t.length()) {
        int j=i;
        while (j<t.length() && t[j]=='F') j++;
        int L = j-i;
        //cout<<L<<endl;
        //cout<<tt[id]<<" "<<id<<" "<<L<<endl;
        for (int s=0;s<maxn;s++) f[id][tt[id]][s]=0;
        for (int s=0;s<maxn;s++) {
            if (s+L < maxn) f[id][tt[id]][s+L] = max(f[id][tt[id]][s+L],f[id][1-tt[id]][s]);
            if (s-L >=0 && time>0) f[id][tt[id]][s-L] = max(f[id][tt[id]][s-L],f[id][1-tt[id]][s]);
        }
       // cout<<f[id][0][N-1]<<" "<<f[id][0][N+1]<<endl;
        tt[id] = 1-tt[id];
        id = 1-id;
        i = j+1;
        time++;
    }

    if (f[0][1-tt[0]][N+x] && f[1][1-tt[1]][N+y]) cout<<"Yes";
    else cout<<"No";

}
