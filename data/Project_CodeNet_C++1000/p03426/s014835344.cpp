/*
 Author : Alokit Kumar
  */
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
 
 int32_t main()
 {
   int t,n,i,j,k,l=0,d,q,m,r,x,y,x1,y1;
   cin>>n>>m>>d;
   map<int,pair<int,int> > m1;
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=m;j++)
     {
       cin>>l;
       m1[l]={i,j};
     }
   }
   int a[n*m+1];
   memset(a,0,sizeof(a));
   for(i=1;i<=n*m;i++)
   {
     if(a[i]==0){
     for(j=i+d;j<=n*m;j+=d)
      {
        x=m1[j-d].first,y=m1[j-d].second;
        x1=m1[j].first,y1=m1[j].second;
        a[j]=a[j-d]+abs(x-x1)+abs(y-y1);
      }
     }
   }
   cin>>q;
   while(q--){
     cin>>l>>r;int s=0;
     s=a[r]-a[l];
     cout<<s<<"\n";
   }
 }