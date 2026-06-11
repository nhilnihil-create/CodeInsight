
#include<bits/stdc++.h>
using namespace std;

//int ans[305][305];

int main()
{


     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
   /* #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   */
 int n,k;
 cin>>n>>k;
 double total=0.0000000000000;

 for(int i=1;i<=n;i++)
 {
    double temp=1.0000000000000;
    int j=i;
    while(j<k)
    {
      j*=2;
      temp=temp*0.5000000000;
    }

    total+=temp;
 }

 //cout<<total<<endl;
 cout<<fixed<<setprecision(20)<<(total/n)<<endl;

   return 0;
    
}