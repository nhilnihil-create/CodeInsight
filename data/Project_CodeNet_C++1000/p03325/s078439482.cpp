///بِسْمِ الّٰلهِ الرَّحْمٰنِ الرَحِيْمِ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
     ios_base::sync_with_stdio(false);cin.tie(NULL);
     ll int i,n,t,j=0,p,x,a=0,b,l=0,r=0,y,k,c,sum=0,m,d;

     cin>>n;
     ll int ara[n];
     for(i=0;i<n;i++){
        cin>>ara[i];
        p=ara[i];l=0;
        while(p%2==0){
           sum++;
           p/=2;
        }
     }
     cout<<sum<<endl;

     return EXIT_SUCCESS;
}

