#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    int n,x;cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int sum=0;
    int ans;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==x){
            ans=i+1;break;
        }
        else if(sum>x){
            ans=i;break;
        }
    }
    if(sum<x) ans=n-1;
    cout<<ans<<endl;
    return 0;
}