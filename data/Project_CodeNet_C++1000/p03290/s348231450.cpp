#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int d,g;
    cin >> d >> g;
    int p[10],c[10];
    bool e[10];
    rep(i,d) cin >> p[i] >> c[i];
    int ans = 1e9;
    for(int i=0; i<(1<<d); i++){
        for(int j=0; j<d; j++){
            if(i>>j & 1) e[j]=true;
            else e[j]=false;
        }
        int now = 0;
        int cost = 0;
        for(int j=0; j<d; j++){
            if(e[j]) {
                now += c[j]+100*(j+1)*p[j];
                cost += p[j];
            }
        }
        if(now >= g){
            ;
        }
        else{
            bool check = false;
            for(int j=d-1; j>=0; j--){
                if(e[j]) continue;
                //need more g-now points
                if(g-now <= (j+1)*100*p[j]){
                    cost += ( (g-now)%((j+1)*100) == 0 ? (g-now)/((j+1)*100) : (g-now)/((j+1)*100)+1);
                    check = true;
                    break;
                }else{
                    now -= (j+1)*100*p[j];
                    cost += p[j];
                }
            }
            if(!check) continue;
        }
        ans = min(ans,cost);
    }
    cout << ans << endl;
    return 0;
}