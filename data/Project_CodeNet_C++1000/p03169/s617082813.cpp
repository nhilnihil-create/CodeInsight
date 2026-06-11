#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long double ll;
int t,n,m,k;
ll f[301][301][301];
ll calc(int x,int y,int z){

if(f[x][y][z]==0){
    ll s=0,p=0;
    if(x!=0){
        s+=x*calc(x-1,y,z);
        p+=x;
    }
    if(y!=0){
        s+=y*calc(x+1,y-1,z);
        p+=y;
    }
    if(z!=0){
        s+=z*calc(x,y+1,z-1);
        p+=z;
    }
        //cout<<s<<endl;
        s/=p;
        f[x][y][z]=s+(n/(p));
        return s+(n/(p));
}else{
return f[x][y][z];
}
}
int main(){
        cout<<fixed<<setprecision(10);
//cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

cin>>n;
ll a[3];
memset(a,0,sizeof a);
for(int i=0;i<n;i++){
ll x;
cin>>x;
if(x==1){a[0]++;}
if(x==2){a[1]++;}
if(x==3){a[2]++;}
}
ll q=(ll)(n);
f[1][0][0]=q;

for(int i=2;i<=n;i++){
    f[i][0][0]=q/i+f[i-1][0][0];
}
f[0][1][0]=2*f[1][0][0];
f[0][0][1]=3*f[1][0][0];
//f[2][0][0]=n/2+f[1][0][0];
cout<<calc(a[0],a[1],a[2])<<endl;
for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
        //cout<<f[j][i][0]<<" ";
    }
    //cout<<endl;
}
//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;

}

