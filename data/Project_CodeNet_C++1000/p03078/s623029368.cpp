#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    long long int a[x],b[y],c[z],d[3000002];
    for(int i=0;i<x;i++)cin >> a[i];
    for(int i=0;i<y;i++)cin >> b[i];
    for(int i=0;i<z;i++)cin >> c[i];
    int count=0;
    //if(x*y*z<=3000){
    //    for(int i=0;i<x;i++)for(int j=0;j<y;j++)for(int l=0;l<z;l++){
    //        d[count]=-a[i]-b[j]-c[l];
    //        count++;
    //    }
    //    sort(d,d+x*y*z);
    //}
    //else{
        long long int e[x*y];
        for(int i=0;i<x;i++)for(int j=0;j<y;j++){
            e[count]=-a[i]-b[j];
            count++;
        }
        sort(e,e+count);
        int count2=0;
        for(int i=0;i<k;i++)for(int l=0;l<z;l++){
            d[count2]=e[i]-c[l];
            count2++;
        }
        sort(d,d+count2);
    //}
    for(int i=0;i<k;i++)cout << -d[i] << endl;
}