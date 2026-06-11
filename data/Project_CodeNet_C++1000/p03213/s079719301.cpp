#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    map<int,int>a;
    set<int>b;
    for(int i=2;i<=n;++i){
        int m=i;
        for(int j=2;j*j<=m;++j){
            if(m%j==0){
                b.insert(j);
                while(m%j==0){
                    m/=j;
                    a[j]++;
                }
            }
        }
        if(m!=1){a[m]++;b.insert(m);}
    }
    int c74=0,c24=0,c14=0,c4=0,c2=0;
    for(auto x:b){
        if(a[x]>=74)c74++;
        else if(24<=a[x])c24++;
        else if(14<=a[x])c14++;
        else if(4<=a[x])c4++;
        else if(2<=a[x])c2++;
    }
    int ans=0;
    ans+=c74;
    ans+=(c74+c24)*((c74+c24)-1)+(c74+c24)*(c14+c4+c2);
    ans+=(c74+c24+c14)*(c74+c24+c14-1)+(c74+c24+c14)*c4;
    ans+=(c74+c24+c14+c4)*(c74+c24+c14+c4-1)*(c74+c24+c14+c4-2)/2+(c74+c24+c14+c4)*(c74+c24+c14+c4-1)/2*c2;
    cout<<ans<<endl;
}