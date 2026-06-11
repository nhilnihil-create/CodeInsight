#include <bits/stdc++.h>
using namespace std;
const int N=(1<<18);
int n, a[N+10];
pair<int,int> f[N+10];
inline void up(pair<int,int> &a,pair<int,int> b){
    if (b.second>=a.first){
        a=b;
    }
    else if (b.first>=a.first){
        a.second=a.first;
        a.first=b.first;
    }
    else if (b.first<a.first && b.first>=a.second){
        a.second=b.first;
    }
}
int main(){
    cin>>n;
    for (int i=0;i<(1<<n);++i){
        scanf("%d", &a[i]);
        f[i].first=a[i];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<(1<<n);j++){
            if (j&(1<<i)) up(f[j], f[j^(1<<i)]);
        }
    }
    int ans=0;
    for (int i=1;i<(1<<n);++i){
        ans=max(ans, f[i].first+f[i].second);
        printf("%d\n", ans);
    }
}