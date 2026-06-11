#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int substring(string s, string t, int m)
{    
    int i, k, j;
     for(i=m;i<s.length();i++)
    {   
        k=i;
       for(j=0;j<t.length();j++)
       {
           if(t[j]!=s[k]&&s[k]!='?')
           {
               break;
           }
           k++;
       }
       if(j==(t.length()))
       {
           return i;
       }
    }
    return -1;
}

int main()
{

     string s, t;
     cin>>s>>t;
     int l1=s.length();
     int l2=t.length();
     if(l1<l2)
     {
         cout<<"UNRESTORABLE"<<endl;
         return 0;
     }
     string ans="";
     string temp;
     bool is=false;
     for(int i=0;i<l1;i++)
     {   
         temp=s;
         int j=substring(temp, t, i);
      //   cout<<j<<endl;
         if(j!=-1)
         {
              for(int k=0;k<l2;k++)
              {
                 temp[j]=t[k];
                 j++;
              }
              for(int k=0;k<l1;k++)
              {
                  if(temp[k]=='?')
                  {
                      temp[k]='a';
                  }
              }
              if(ans.empty())
              {
                  ans=temp;
              }
              else
              {
                  ans=min(ans, temp);
              }
           //   cout<<ans<<endl;
              is=true;
         }
     }
     if(is)
     {
         cout<<ans<<endl;
     }
     else{
         cout<<"UNRESTORABLE"<<endl;
     }
    


    return 0; 
}