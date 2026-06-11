#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
 
int N,K;
int T[111111],D[111111];
 
bool ex[111111];
 
signed main(){
    cin>>N>>K;
    rep(i,N)cin>>T[i]>>D[i];
 
    vector<pint>vs;
    rep(i,N)vs.pb(pint(D[i],i));
    sort(all(vs));reverse(all(vs));
 
    int ans=0;
    int num=0,sum=0;
    priority_queue<int,vint,greater<int>>que;
    for(int i=0;i<N;i++){
        int k=vs[i].se;
        if(i<K){
            sum+=D[k];
            if(!ex[T[k]]){
                ex[T[k]]=true;
                num++;
            }
            else{
                que.push(D[k]);
            }
        }
        else if(!ex[T[k]]&&que.size()){
            sum-=que.top();
            que.pop();
            ex[T[k]]=true;
            num++;
            sum+=D[k];
        }
        chmax(ans,num*num+sum);
    }
    cout<<ans<<endl;
    return 0;
}