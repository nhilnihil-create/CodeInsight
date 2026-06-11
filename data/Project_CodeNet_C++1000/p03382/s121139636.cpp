#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n,a[N];
int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];

        int uR=*max_element(a+1,a+n+1),uL=-1;
        
        for(int i=1;i<=n;i++) if (a[i]<uR){
                int ow=min(uL,uR-uL);
                int nw=min(a[i],uR-a[i]);
                if (nw>ow) uL=a[i];
        }
        cout<<uR<<" "<<uL;
}
