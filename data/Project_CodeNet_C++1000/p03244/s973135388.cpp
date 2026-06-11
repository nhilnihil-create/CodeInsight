#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<string>;
using P =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    rep(i,n)cin>>v[i];
    vector<int> a(100001,0);
    vector<int> b(100001,0);
    rep(i,n){
        if(i%2==0)++a[v[i]];
        else ++b[v[i]];
    }
    int maxa[2]={};
    int maxb[2]={};
    int indexa[2]={};
    int indexb[2]={};

    for(int i=1;i<100001;++i){
        if(a[i]>=maxa[0]){
            maxa[1]=maxa[0];
            indexa[1]=indexa[0];
            maxa[0]=a[i];
            indexa[0]=i;
        }else if(a[i]>=maxa[1]){
            maxa[1]=a[i];
            indexa[1]=i;
        }

        if(b[i]>=maxb[0]){
            maxb[1]=maxb[0];
            indexb[1]=indexb[0];
            maxb[0]=b[i];
            indexb[0]=i;
        }else if(b[i]>=maxb[1]){
            maxb[1]=b[i];
            indexb[1]=i;
        }
    }

    int ans=0;
    if(indexa[0]==indexb[0])ans=max(maxa[0]+maxb[1],maxa[1]+maxb[0]);
    else ans=maxa[0]+maxb[0];

    cout<<n-ans<<endl;
    return 0;
}