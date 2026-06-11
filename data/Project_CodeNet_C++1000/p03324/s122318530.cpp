///بِسْمِ الّٰلهِ الرَّحْمٰنِ الرَحِيْمِ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
     ios_base::sync_with_stdio(false);cin.tie(NULL);
     ll int i,n,t,j=0,p,x,a=0,b,l=0,r=0,y,k,c,sum=0,m,d;p=100;
     cin>>a>>b;
     if(b==100){
        if(a==0){
            cout<<101<<endl;
        }
        else if(a==1){
            cout<<10100<<endl;
        }
        else{
            cout<<1010000<<endl;
        }
     }
     else{
     for(i=0;i<a;i++){
        b*=100;
     }

     cout<<b<<endl;
}


     return EXIT_SUCCESS;
}

