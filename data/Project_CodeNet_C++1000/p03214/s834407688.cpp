#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int sum=0;
    rep(i,n){
        cin>>vec[i];
        sum+=vec[i];
    }
    int ave=sum;
    int ans,minv;
    rep(i,n){
        if(i==0){
            minv=abs(n*vec[i]-ave);
            ans=i;
        }else if(abs(n*vec[i]-ave)<minv){
            minv=abs(n*vec[i]-ave);
            ans=i;
        }
    }
    cout<<ans<<endl;
}
