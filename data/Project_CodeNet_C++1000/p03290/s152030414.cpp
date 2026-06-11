#include<bits/stdc++.h>

using namespace std;

int main(){
    int d,g;
    cin >> d >> g;
    int p[d];
    int c[d];
    for(int i=0;i<d;i++){
        cin >> p[i] >> c[i];
    }
    int ans=1e9;

    for(int i=0;i<(1<<d);i++){
        int score=0;
        int num=0;
        int rest_max=-1;
        for(int j=0;j<d;j++){
            //最下位bitが1or0
            if((i>>j) & 1){
                score+=100*p[j]*(j+1)+c[j];
                num+=p[j];
            }else{
                rest_max=j;
            }
        }
        if(score<g){
            int s1=100*(rest_max+1);
            int need=(g-score+s1-1)/s1;
            if(need>=p[rest_max]) continue;
            num+=need;
        }
        ans=min(ans,num);
    }
    cout << ans;

    return 0;
}
