#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int x,y;
  cin>>s>>x>>y;
  int N=s.size();
  int i;
  for(i=0;i<N;i++)if(s[i]=='T')break;
  x-=i;
  x=max(x,-x);
  y=max(y,-y);
  int j=i;
  int k=0;
  int out=0;
  for(i=j+1;i<N;i++)if(s[i]=='T')k++;
  std::vector<int> vx((k+1)/2),vy(k/2+1);
  int l=-1;
  int ix=0;
  int iy=0;
  int ka=0;
  for(i=j+1;i<N;i++){
    if(s[i]=='T'){
      if(l==1){
        vx[ix]=ka;
        ix++;
      }
      else{
        vy[iy]=ka;
        iy++;
      }
      l*=-1;
      ka=0;
    }
    else ka++;
  }
  if(s[N-1]=='F'){
    if(l==1){
      vx[ix]=ka;
      ix++;
    }
    else{
      vy[iy]=ka;
      iy++;
    }
  }
  sort(vx.begin(),vx.end());
  sort(vy.begin(),vy.end());
  int xc=0;
  for(int i=0;i<(k+1)/2;i++)xc+=vx[i];
  //cout<<54321<<" "<<xc<<endl;
  xc-=x;
  //cout<<54321<<" "<<xc<<endl;
  if(xc%2||xc<0)out++;
  else{
    xc/=2;
    vector<vector<bool>> hx((k+1)/2+1,vector<bool>(xc+1));
    hx[0][0]=true;
    for(int j=1;j<xc+1;j++)hx[0][j]=false;
    for(int i=1;i<(k+1)/2+1;i++){
      for(int j=0;j<(xc+1);j++){
         hx[i][j]=hx[i-1][j];
         if(j-vx[i]>=0)hx[i][j]=(hx[i][j]||hx[i-1][j-vx[i]]);
      }
    }
    if(hx[(k+1)/2][xc]==false)out++;
  }
  ////////
  int yc=0;
  for(int i=0;i<k/2+1;i++)yc+=vy[i];
  yc-=y;
  if(yc%2||yc<0)out++;
  else{
    yc/=2;
    vector<vector<bool>> hy(k/2+1+1,vector<bool>(yc+1));
    hy[0][0]=true;
    for(int j=1;j<yc+1;j++)hy[0][j]=false;
    for(int i=1;i<k/2+1+1;i++){
      for(int j=0;j<(yc+1);j++){
         hy[i][j]=hy[i-1][j];
         if(j-vy[i]>=0)hy[i][j]=(hy[i][j]||hy[i-1][j-vy[i]]);
      }
    }
    if(hy[k/2+1][yc]==false)out++;
  }
  //cout<<xc<<endl;
  //for(int i=0;i<(k+1)/2;i++)cout<<vx[i]<<" ";
  //cout<<endl;
  //for(int i=0;i<k/2+1;i++)cout<<vy[i]<<" ";
  //cout<<endl;
  //cout<<ka<<" "<<ix<<endl;
  if(out)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
