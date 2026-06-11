#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
typedef  long long     ll ;
using namespace std;
void GO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=10009;
int a[]={2,5,5,4,5,6,3,7,6};
vector< pair<int,int> > v;
bool mark[N];
vector<int> ans;
int mem[N];
int solve(int rem){
    if(rem==0){
        return 0;
    }
    int &ret=mem[rem];
    if(ret!=-1) return ret;
    int ans=-100000;
    for(int i=1;i<=9;i++){
        if(mark[i]==0||a[i-1]>rem)
         continue;
        ans=max(ans,1+solve(rem-a[i-1]));
    }
    return ret=ans;
}
void print(int rem){

   int mx=0,d=0;
   for(int i=1;i<=9;i++){
        if(mark[i]==0||a[i-1]>rem)
          continue;
        int ret=1+solve(rem-a[i-1]);
        if(ret>mx){
            mx=ret;
            d=i;
        }
        else if(ret==mx){
            mx=ret;
            d=max(d,i);
        }
    }
    if(d!=0)
    ans.pb(d);
    if(d!=0)
    print(rem-a[d-1]);

}
int main(){
    GO();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int no;
        cin>>no;
        mark[no]=1;
    }
    clr(mem,-1);
    int mx=solve(n);
    if(mx<=0){
        cout<<"0"<<endl;
        return 0;
    }
    print(n);

    for(int i=0;i<sz(ans);i++) cout<<ans[i];
    cout<<endl;
}

