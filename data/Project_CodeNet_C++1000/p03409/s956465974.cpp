#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> p;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;

int main(){
    int n;cin>>n;
    vector<pii> red(n),blue(n);
    for(int i=0;i<n;++i){
        int a,b;cin>>a>>b;
        red[i]=make_pair(a,b);
    }
    for(int i=0;i<n;++i){
        int c,d;cin>>c>>d;
        blue[i]=make_pair(c,d);
    }
    sort(red.begin(),red.end());
    sort(blue.begin(),blue.end());
    vector<bool> used(n,false);
    int ans=0;
    for(int i=0;i<n;++i){
        int maxv=-1;
        int index=-1;
        for(int j=0;j<n;++j){
            if(!used[j]&&red[j].first<blue[i].first&&red[j].second<blue[i].second){
                if(red[j].second>maxv){
                    index=j;
                    maxv=red[j].second;
                }
            }
        }
        if(index!=-1){
            ans++;
            used[index]=true;
        }
    }
    cout<<ans<<endl;
    return 0;
}