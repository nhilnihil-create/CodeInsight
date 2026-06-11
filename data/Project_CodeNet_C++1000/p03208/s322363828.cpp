#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    rep(i,n){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int minv;
    for(i=0;i+k-1<vec.size();i++){
        if(i==0)minv=vec[i+k-1]-vec[i];
        else{
            minv=min(minv,vec[i+k-1]-vec[i]);
        }
    }
    cout<<minv<<endl;
}