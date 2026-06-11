#include <iostream>
using namespace std;
int main(void){
    int n,m,c,b[20],ans=0,i,j;
    cin >> n >> m >> c;
    for(i=0;i<m;i++) cin >> b[i];
    for(i=0;i<n;i++){
        int a,tmp=0;
        for(j=0;j<m;j++){
            cin >> a;
            tmp+=a*b[j];
        }
        if(tmp+c>0) ans++;
    }
    cout << ans;
}