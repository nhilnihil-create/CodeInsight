#include<bits/stdc++.h>
using namespace std;
 
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int ans,t;
long long i,a,b,u,c,d,e,f,g,h;
int main()
{
//	freopen("3.in","r",stdin);
//	freopen("4.out","w",stdout);
	t=read();
	while(t--){
		a=read(); b=read();
		if(a<b)swap(a,b);
		u=(a*b-1)/(b+1);
		if(u<=b+1)ans=u; else
		{
 
		h=u+b+1;
		if((h/2*(h-h/2))<=a*b-1)ans=u;else{
//			g=sqrt(a*b-0.9);


//tepan//da xiao// 0 1 2 ... //
           // g=sqrtl((long double)a*b-0.9);
 g=sqrt((long double)a*b-0.9); //(a*b) (...) //ll -4//()
            //sqrt//(long double) //noi linux
			
//二分套三分 

			ans=min(u-g+1,g-(b+1)+1);
			if(u-g+1>g-(b+1)+1 && g*(g+1)<=a*b-1)++ans;
            
//            int v=b+1;
//            for(long long i=u; i>=g; --i){
//            	if(i*v<=a*b-1)
//            	{
//            	    ++ans;
//            	    ++v;
//            	    if(v==292703660)
//					int hh=0; 
//                }
//			}
            
			ans+=g-1;
		}
		
	    }
		ans+=b-1;
		printf("%d\n",ans);
	} 
}
