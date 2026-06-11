#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

const double PI=(acos(-1));

int n=0,a=0,b=0,c=0;
int ans=10000;
vector<int> l(n,0);
vector<int> vc(n,0);

void calc(vector<int> v){
    int aa=0,bb=0,cc=0;
    int s=0,t=0,r=0;
    int mp=0;
    rep(i,n){
        if(v[i]==0){
            aa+=l[i];
            ++s;
        }else if(v[i]==1){
            bb+=l[i];
            ++t;
        }else if(v[i]==2){
            cc+=l[i];
            ++r;
        }else{
        }
    }
    mp+=(s==0)?10000:(s-1)*10;
    mp+=(t==0)?10000:(t-1)*10;
    mp+=(r==0)?10000:(r-1)*10;
    mp+=abs(a-aa)+abs(b-bb)+abs(c-cc);
    ans=min(ans,mp);
}

void dfs(int d,vector<int> v){
    if(d==n){
        calc(v);
        return;
    }
    for(int i=0;i<4;++i){
        v[d]=i;
        dfs(d+1,v);
    }
}

int main(){
    cin>>n>>a>>b>>c;
    l.assign(n,0);
    vc.assign(n,0);
    rep(i,n)cin>>l[i];
    dfs(0,vc);
    cout<<ans<<endl;
}
