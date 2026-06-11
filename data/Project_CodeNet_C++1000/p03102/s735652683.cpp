#include <bits/stdc++.h>
using namespace std;
int n,m,c,a[200][200],b[200],k;
long long sum;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n>>m>>c;
for(int i=0;i<m;i++){
    cin>>b[i];
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
}
for(int i=0;i<n;i++){
        sum=0;
    for(int j=0;j<m;j++){
    sum+=(a[i][j]*b[j]);
    }
sum+=c;
if(sum>0)k++;
}
cout<<k;
return 0;}

