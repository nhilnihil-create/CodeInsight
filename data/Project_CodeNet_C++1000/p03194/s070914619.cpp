///بِسْمِ الّٰلهِ الرَّحْمٰنِ الرَحِيْمِ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int i,n,t,j=0,p,x,a=0,b,l=0,r=0,y,k,c,sum=0,m,d,z=1;
    cin>>n>>p;
    for(i=2;i*i<=p;i++){
        l=0;
        if(n==1){
            cout<<p<<endl;
            return 0;
        }
        while(p%i==0)l++,p/=i;
        for(j=1;j*n<=l;j++) z*=i;
    }
    cout<<z<<endl;

    return EXIT_SUCCESS;
}

