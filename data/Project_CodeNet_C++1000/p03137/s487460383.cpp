#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n,m,x[100000],y[100000],ans=0,i;
    cin >> n >> m;
    for(i=0;i<m;i++) cin >> x[i];
    sort(x,x+m);
    for(i=0;i<m-1;i++) y[i] = x[i+1]-x[i];
    sort(y,y+m-1);
    for(i=0;i<m-n;i++) ans+=y[i];
    cout << ans;
}