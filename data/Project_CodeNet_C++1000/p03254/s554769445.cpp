#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> vec(n);
    rep(i,n){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int ans=0;
    for(i=0;x>0;i++){
        x-=vec[i];
        if(x>=0)ans++;
        if(x>=0&&i==n-1){
            if(x!=0)ans--;
            break;
        }
    }
    cout<<ans<<endl;
}