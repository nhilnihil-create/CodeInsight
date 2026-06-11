#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

char que(int x){
    printf("%d\n",x);
    fflush(stdout);
    char c[8];
    scanf("%s", c);
    if(c[0]=='V')exit(0);
    return c[0];
}

int main(){
    int n;
    scanf("%d", &n);
    int l=0,r=n;
    char bl=que(l);
    while(r-l>1){
        int mid=(l+r)/2;
        char br=que(mid);
        if((bl!=br&&(mid-l)%2==0)||(bl==br&&(mid-l)%2==1))r=mid;
        else l=mid,bl=br;
    }
}