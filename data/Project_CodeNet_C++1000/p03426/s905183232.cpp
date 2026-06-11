#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,d,a,q,l,r,i,j;
  cin>>h>>w>>d;
  vector<int> x(h*w),y(h*w);
  vector<vector<int>> z(d,vector<int>(0));
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin>>a;
      x.at(a-1)=i;
      y.at(a-1)=j;
    }
  }
  for(i=0;i<h*w;i++){
    if(i/d==0) z.at(i%d).push_back(0);
    else z.at(i%d).push_back(z.at(i%d).at(i/d-1)+abs(x.at(i)-x.at(i-d))+abs(y.at(i)-y.at(i-d)));
  }
  cin>>q;
  for(i=0;i<q;i++){
    cin>>l>>r;
    l--;
    r--;
    cout<<z.at(r%d).at(r/d)-z.at(l%d).at(l/d)<<endl;
  }
}