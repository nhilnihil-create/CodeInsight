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
typedef pair<int,int> ii;
typedef pair<int,ii> pii;
typedef long long ll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};
int main(){
    int N,C;cin>>N>>C;
    vector<pii> ch(N);
    for(int i=0;i<N;++i){
        int s,t,c;cin>>s>>t>>c;s--;t--;
        ch[i]=pii(c,ii(s,t));
    }
    sort(ch.begin(),ch.end());
    vector<int> S(1e5+1,0);
    for(int i=0;i<N;++i){
        int c=ch[i].first;
        int s=ch[i].second.first;
        int t=ch[i].second.second;
        if(!(i>0&&c==ch[i-1].first&&ch[i-1].second.second==s)){
            S[s]++;
        }
        if(!(i<N-1&&c==ch[i+1].first&&t==ch[i+1].second.first)){
            S[t+1]--;
        }
    }
    int mx=S[0];
    for(int i=1;i<=1e5;++i){
        S[i]+=S[i-1];
        mx=max(mx,S[i]);
    }
    cout<<mx<<endl;
    return 0;
}