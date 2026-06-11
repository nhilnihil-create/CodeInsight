#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>

 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define LLIandI pair<long long int , int>
#define ll long long


bool d[10002][20002];//[i][j]=i番目の遷移で座標j-8000
int main(void){
   char s[10000];
   scanf("%s",s);
   int x,y;
   scanf("%d %d",&x,&y);
   int sx=-1,sy=0;int vec=0;
   int cnt=0;
   vector<int> ud;
   vector<int> rl;
   int N=strlen(s);
   //prepare
   rep(i,N){
       if(s[i]=='F'){
           cnt++;
       }else{
           if(vec%2==0){
               if(sx>-1)rl.pb(cnt);
               else sx=cnt;
           }else ud.pb(cnt);
           cnt=0;vec++;
       }
       if(i==N-1&&cnt>0){
           if(vec%2==0){
               if(sx>-1)rl.pb(cnt);
               else sx=cnt;
           }else ud.pb(cnt);
       }
   }
   //solve
   
   rep(i,ud.size()+2)rep(j,20000){d[i][j]=false;}
   //updown
   d[0][sy+10000]=true;
   rep(i,ud.size()){
       rep(j,20000){
           if(j+ud[i]>-1&&j+ud[i]<20000&&d[i][j]==true){d[i+1][j+ud[i]]=true;}
           if(j-ud[i]>-1&&j-ud[i]<20000&&d[i][j]==true){d[i+1][j-ud[i]]=true;}
       }
   }
    if(d[ud.size()][y+10000]==false){printf("No\n");return 0;}
   rep(i,rl.size()+2)rep(j,20000){d[i][j]=false;}
   //rightleft
   d[0][sx+10000]=true;
   rep(i,rl.size()){
       rep(j,20000){
          if(j+rl[i]>-1&&j+rl[i]<20000&&d[i][j]==true)d[i+1][j+rl[i]]=true;
          if(j-rl[i]>-1&&j-rl[i]<20000&&d[i][j]==true)d[i+1][j-rl[i]]=true;
       }
   }
   if(d[rl.size()][x+10000]==false){printf("No\n");return 0;}
   printf("Yes\n");return 0;
}
