#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<pair<int,int>> list(n);
    rep(i,n){
        cin>>x>>y;
        list[i]=make_pair(x,y);
    }
    sort(all(list));
    long long int ans=0;
    for(i=0;m>=0;i++){
        if(list[i].second>=m){
            ans+=(long long int)m*list[i].first;
            break;
        }else{
            ans+=(long long int)list[i].first*list[i].second;
            m-=list[i].second;
        }
    }
    cout<<ans<<endl;
}