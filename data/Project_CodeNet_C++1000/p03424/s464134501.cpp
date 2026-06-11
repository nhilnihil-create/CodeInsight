/*
 Author : Alokit Kumar
  */
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
 
 int32_t main()
 {
   int t,n,i,j,k,l;
   cin>>n;
   char ch;bool hi=false;
   for(i=1;i<=n;i++)
   {
     cin>>ch;
     if(ch=='Y')
     {
       hi=true;
     }
   }
   if(hi) cout<<"Four";
   else cout<<"Three";
 }