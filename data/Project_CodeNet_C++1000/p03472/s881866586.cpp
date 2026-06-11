#include<iostream>
 #include<cstdio>
 #include<cmath>
 #include<algorithm>
 //#include<cstring>
 using namespace std;
 struct knife
 {
     int ai;
     bool f;
 }m[2000018];
 inline int read()
 {
   int p=0,f=1;char c=getchar();
   while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
   while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}
   return f*p;}
 int N,H,ans;
 bool cmp(knife x,knife y)
 {
     return x.ai>y.ai;
 }
 int main()
 {
     N=read(),H=read();
     for(int i=1;i<=N;i++)
         m[i].ai=read(),
   	  m[i+N].ai=read(),
         m[i+N].f=true; 
     sort(m+1,m+1+N*2,cmp); 
     int ans=0;           
     for(int i=1;i<=2*N;i++) 
        {
          if(m[i].f) 
	        {ans++;
	         H-=m[i].ai;}
          else
             {
              int u=H%m[i].ai;
	          ans+=H/m[i].ai;
              if(u)ans++;
	  	    H=-1;
             }
           if(H<=0)
             {printf("%d",ans);
              return 0;}
        }
 }