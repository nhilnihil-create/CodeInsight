#include<bits/stdc++.h>
using namespace std;
#define Y cout<<"YES"<<endl;
#define N cout<<"NO"<<endl;
#define tc int t; cin>>t; while(t--)
#define eki int n; cin>>n;
#define loop for(int i=0; i<n; i++)
int main()
{  
   
   float a, sum1=0, sum2=0;
   string s;
   tc {
   cin>>a>>s;
   if(s=="JPY")
   sum1=sum1+a;
   else sum2=sum2+a;
   }
   sum2=sum2*380000.0;
   sum1= sum1+sum2;
   cout<<sum1<<endl;
   
   
}


