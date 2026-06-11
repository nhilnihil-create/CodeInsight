#include<bits/stdc++.h>
using namespace std;

int main(){
    int d,g;
    cin >> d >> g;
    pair<int,int> p[d];
    int sum[d];
    for(int i=0;i<d;i++){
        cin >> p[i].first >> p[i].second;
        sum[i]=(i+1)*100*p[i].first+p[i].second;
    }
    int ans=1e9;
    int tmp;
    int count;
    for(int i=0;i<(1<<d);i++){
        tmp=0;
        count=0;
        for(int j=0;j<d;j++)if(i & (1<<j)){
            tmp+=sum[j];
            count+=p[j].first;
        }
        if(tmp<g){
            for(int j=d-1;j>=0;j--){
                if(!(i & (1<<j))){
                    count+=min((g-tmp+j*100)/((j+1)*100),p[j].first);
                    tmp+=min(g-tmp,p[j].first*(j+1)*100);
                    break;
                }
            }
        }
        if(tmp>=g)ans=min(count,ans);
    }
    cout << ans;
}