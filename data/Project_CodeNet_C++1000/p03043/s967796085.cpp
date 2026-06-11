#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    int n,k;
    cin>>n>>k;
    double ans=0;
    for(int i=1;i<=n;i++){
        ll point=i;
        double pro=1;
        while(point<k){
            point*=2;
            pro*=0.5;
        }
        ans+=pro/n;
    }
    printf("%.10f",ans);
}