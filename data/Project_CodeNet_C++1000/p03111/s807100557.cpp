#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;
int abs(int x){
    if(x<0) return -x;
    else return x;
}
int main(){
    int n;
    cin >> n;
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> l(n);
    rp(i,n) cin >> l.at(i);
    int ans=10000000;
    for(int i=0; i<(1<<(2*n)); i++){
        int fora=0; int forb=0; int forc=0;
        int ina=0,inb=0,inc=0;
        rp(j,n){
            if((i>>(2*j))%4==1){
                fora += l.at(j);
                ina++;
            }
            if((i>>(2*j))%4==2){
                forb += l.at(j);
                inb++;
            }
            if((i>>(2*j))%4==3){
                forc += l.at(j);
                inc++;
            }
        }
        if(ina*inb*inc==0) continue;
        int cand=abs(fora-a)+abs(forb-b)+abs(forc-c)+10*(ina+inb+inc-3);
        ans=min(ans,cand);
    }
    cout << ans << endl;
    return 0;
}