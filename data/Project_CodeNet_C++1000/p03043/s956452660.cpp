#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin>>n>>k;
    double ans=0;
    for(int i=1;i<=n;i++){
        double r=i,p=1;
        while(r<k){
            r*=2;
            p/=2.0;
        }
        ans+=p/n;
    }
    printf("%.15f\n",ans);
}