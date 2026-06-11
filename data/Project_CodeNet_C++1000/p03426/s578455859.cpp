#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    int h,w,d;
    cin>>h>>w>>d;
    vector<vector<int>> a(h,vector<int>(w));
    map<int,pair<int,int>> m;
    map<pair<int,int>,int> m2;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
            a[i][j]--;
            m[a[i][j]]=make_pair(i,j);
        }
    }

    int q;
    cin>>q;
    vector<int> l(q),r(q);
    for(int i=0; i<q; i++){
        cin>>l[i]>>r[i];
        l[i]--;
        r[i]--;
    }
    vector<vector<ll>> sums(d,vector<ll>((h*w/d)+1));
    vector<bool> visit(h*w,false);
    for(int i=0; i<d; i++){
        if(visit[i]) continue;
        for(int j=0; i+(j+1)*d<h*w; j++){
            //cout<<i+(j+1)*d<<" ";
            pair<int,int> now=m[i+j*d];
            pair<int,int> next=m[i+(j+1)*d];
            sums[i%d][j+1]=(sums[i%d][j]+(abs(now.first-next.first)+abs(now.second-next.second)));
        }
    }
    for(int i=0; i<q; i++){
        //cout<<sums[r[i]%d][(r[i]/d)]<<endl;
        ll tmp=sums[r[i]%d][(r[i]/d)]-sums[r[i]%d][(l[i]/d)];
        cout<<tmp<<endl;
    }

}