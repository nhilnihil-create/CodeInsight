#include <bits/stdc++.h>
using namespace std;

int n,X[1000],Y[1000];
inline int _abs(int a) { return a<0 ? -a : a; }

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",X+i,Y+i);
    
    int pari=((X[0]+Y[0])%2+2)%2;
    for(int i=0;i<n;i++) if(((X[i]+Y[i])%2+2)%2!=pari) { puts("-1"); return 0;}

    vector<int> vs;
    for(int i=30;i>=0;i--) vs.push_back(1<<i);
    if(pari==0) vs.push_back(1);
    printf("%lu\n",vs.size());
    for(auto &v:vs)printf("%d ",v);
    puts("");
    for(int i=0;i<n;i++) {
        long long x=X[i],y=Y[i];
        for(auto &v:vs) {
            if(_abs(x) > _abs(y)) {
                if(x>0) printf("R"), x-=v;
                else printf("L"), x+=v;
            } else {
                if(y<0) printf("D"), y+=v;
                else printf("U"), y-=v;
            }
        }
        puts("");
    }

    return 0;
}
