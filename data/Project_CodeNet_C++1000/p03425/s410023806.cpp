/*
 Author : Alokit Kumar
  */
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
 
 int32_t main()
 {
   int t,n,i,j,k,l=0;
   cin>>n;
   string s;int a[6];memset(a,0,sizeof(a));
   for(i=1;i<=n;i++)
   {
     cin>>s;
     if(s[0]=='M')
      a[1]++;
     else if(s[0]=='A') a[2]++;
     else if(s[0]=='R') a[3]++;
     else if(s[0]=='C') a[4]++;
     else if(s[0]=='H') a[5]++;
   }
   for(i=1;i<=3;i++)
   {
     for(j=i+1;j<=4;j++)
     {
       for(k=j+1;k<=5;k++)
        l+=a[i]*a[j]*a[k];
     }
   }
   cout<<l;
 }