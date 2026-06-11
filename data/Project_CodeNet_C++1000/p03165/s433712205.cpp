#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int mod=10e8+7,maximum=-1;;

 string getmax(string str1,string str2)
{
    string s;
    long long int n1,n2;
    n1=str1.length();
    n2=str2.length();
    long long int i,j;
    long long int dp[n1+1][n2+1];
   
    for(i=0;i<n1+1;i++)
    dp[i][0]=0;
    for(j=0;j<n2+1;j++)
    dp[0][j]=0;
    
     for(i=1;i<n1+1;i++)
     {
         for(j=1;j<n2+1;j++)
         {
             if(str1[i-1]==str2[j-1])
             dp[i][j]=(1+dp[i-1][j-1]);
             else
             {
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             }
             
         }}

    i=n1,j=n2;
    while(i>0&&j>0)
    {
        if(str1[i-1]==str2[j-1])
        {
            s.push_back(str1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            else 
            {
                j--;
            }
            
        }
        
    }

    reverse(s.begin(),s.end());
     
         
   
 
  
    return s;

    

}
int main()
{
     long long int n,weight;
    
    string str1,str2;
   
      
         long long int i;
   
        cin>>str1;
        cin>>str2;
        cout<<getmax(str1,str2)<<"\n";
    
}