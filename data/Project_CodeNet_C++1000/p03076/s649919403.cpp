#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  int a_amari=a%10;
  int b_amari=b%10;
  int c_amari=c%10;
  int d_amari=d%10;
  int e_amari=e%10;
  int sa_a=10-a_amari;
  if(sa_a==10)sa_a=0;
  
  int sa_b=10-b_amari;
  if(sa_b==10)sa_b=0;
  
  int sa_c=10-c_amari;
  if(sa_c==10)sa_c=0;
  
  int sa_d=10-d_amari;
  if(sa_d==10)sa_d=0;
  
  int sa_e=10-e_amari;
  if(sa_e==10)sa_e=0;
  
  int kotae=a/10*10+b/10*10+c/10*10+d/10*10+e/10*10;
  int tasu=0;
  if(a_amari!=0)tasu++;
  if(b_amari!=0)tasu++;
  if(c_amari!=0)tasu++;
  if(d_amari!=0)tasu++;
  if(e_amari!=0)tasu++;
  int saishou=INT_MAX;
  if(a_amari!=0)saishou=min(saishou,a_amari);
  if(b_amari!=0)saishou=min(saishou,b_amari);
  if(c_amari!=0)saishou=min(saishou,c_amari);
  if(d_amari!=0)saishou=min(saishou,d_amari);
  if(e_amari!=0)saishou=min(saishou,e_amari);
  if(tasu>1)kotae+=10*(tasu-1)+saishou;
  else if(tasu==1)kotae+=max({sa_a,sa_b,sa_c,sa_d,sa_e});
  cout<<kotae<<endl;
  return 0;
}