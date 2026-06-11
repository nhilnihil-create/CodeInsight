
 #include<iostream>
 #include<stdio.h>
 #include<cstdlib>
 #include<cstdio>
 #include<string>
 #include<math.h>
 #include<time.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<fstream> 
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 #include<queue>
 #include<deque>
 #include<functional>
 #include<utility>
 #include<list>
 #include<memory>
 
 using namespace std;
 
 int abs(int a,int b)
 {
   if(a>=b) return (a-b);
   else return (b-a);    
 }

 int main()
 {
   string s;
   while(cin>>s)
   {
     int cnt=0;
     int kk[3]={0};
     int sum=0;
     for(int i=0;i<s.length();i++)
     {
       kk[s[i]-'a']++;        
     }
     for(int i=0;i<3;i++)
     { 
       if(kk[i]>0)
       { 
         cnt++;
         sum+=kk[i];
       }
     }
     if(cnt==1)
     { 
       if(sum==1) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
     }
     else if(cnt==2)
     {
       if(sum==2) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;     
     }
     else
     {
       if(abs(kk[0]-kk[1])<=1&&abs(kk[1]-kk[2])<=1&&abs(kk[0]-kk[2])<=1)
       {
         cout<<"YES"<<endl;                                                             
       }    
       else cout<<"NO"<<endl;
     } 
   }
   return 0;
 }
 

        
