#include <bits/stdc++.h>
using namespace std;
int main(void){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int count=0;
    for (int i=0;r*i<=n;i++) {
        for (int j=0;j*g<=n;j++) {
            if (n-(r*i+j*g)>=0&&(n-(r*i+j*g))%b==0) {
                count++;
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<count<<endl;
}