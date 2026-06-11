#include <iostream>
using namespace std;
int main(void){
    int n,m,i,j,x,y,ans=0,a[30]={0};
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> x;
        for(j=0;j<x;j++){
            cin >> y;
            a[y-1]++;
        }
    }
    for(i=0;i<m;i++){
        if(a[i]==n) ans++;
    }
    cout << ans;
}