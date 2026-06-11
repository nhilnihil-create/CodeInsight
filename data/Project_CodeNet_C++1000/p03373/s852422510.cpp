#include <bits/stdc++.h>
using namespace std;
/**
*   @Author: MeGaaaaaaaaaa
*   @InitTime: Mon Sep 09 05:03:34 2019
*   @Idea: 
*
*
*
*
* Happy Solving :)
**/
int main(){
#ifndef ONLINE_JUDGE
 //   freopen("in","r",stdin)
 //   freopen("out","w",stdout)
#endif
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int answer=0;
    if(2*c <= b+a){
       int f=min(x,y);
       answer=f*(2*c);
       x-=f;
       y-=f;
    //   cout<<answer<<endl;
       if(x!=0){
       	  answer+=min((int)((x)*(2*c)),(int)(x*a));
       }
       if(y!=0){
       	  answer+=min((int)(y)*(2*c),(int)(y*b));
       }
   }else{
        answer=a*x+y*b;
   }
   cout<<answer<<endl;






}
