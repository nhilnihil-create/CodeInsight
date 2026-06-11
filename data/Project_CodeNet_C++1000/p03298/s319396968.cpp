#include<cstdio>
#include<map>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef unsigned long long uLL;
const uLL con=371902093;
uLL pw[45],rdm[30],ans;
char s[45];
int n;
map<uLL,int> M;
int main(){
  srand(1234);
  scanf("%d%s",&n,s+1);
  pw[0]=1; for(int i=1;i<=40;i++) pw[i]=pw[i-1]*con;
  for(int i=0;i<=25;i++) rdm[i]=rand()*rand()*rand()*rand();
  for(int i=0;i<=(1<<n)-1;i++){
    uLL h1=0,h2=0; int cnt=0;
    for(int j=1;j<=n;j++)
      if((i>>j-1)&1) h1=h1*con+rdm[s[j]-'a'], cnt++;  
    h1=h1*pw[n-cnt];
    for(int j=n;j>=1;j--)
      if(!((i>>j-1)&1)) h2=h2*con+rdm[s[j]-'a'];
    M[h1-h2]++;
  }
  for(int i=0;i<=(1<<n)-1;i++){
    uLL h1=0,h2=0; int cnt=0;
    for(int j=1;j<=n;j++)
      if((i>>j-1)&1) h1=h1*con+rdm[s[n+j]-'a']; 
    for(int j=n;j>=1;j--)
      if(!((i>>j-1)&1)) h2=h2*con+rdm[s[n+j]-'a'], cnt++;
    h2=h2*pw[n-cnt];
    ans+=M[h2-h1];
  }
  printf("%llu\n",ans);
  return 0;
}
