#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> T;
int main(){
    int n,C;
    cin>>n>>C;
    int s[n],t[n],c[n];
    T p[n];
    for(int i=0;i<n;i++){
        cin>>s[i]>>t[i]>>c[i];
        p[i]={c[i],s[i],t[i]};
    }
    sort(p,p+n);
    int imos[100002]={};
    for(int i=0;i<n-1;i++){
        imos[get<1>(p[i])]++;
        if(get<0>(p[i])==get<0>(p[i+1]) && get<2>(p[i])==get<1>(p[i+1]))imos[get<2>(p[i])]--;
        else imos[get<2>(p[i])+1]--;
    }
    imos[get<1>(p[n-1])]++,imos[get<2>(p[n-1])+1]--;
    int wa[100002];
    wa[0]=imos[0];
    int m=0;
    for(int i=1;i<100002;i++){
        wa[i]=wa[i-1]+imos[i];
        m=max(m,wa[i]);
    }
    cout<<m<<endl;
    return 0;
}