#include<bits/stdc++.h>
using namespace std;

int main(){
  int d,g;
  cin >> d >> g;
  vector<int>ten(d);
  vector<int>bo(d);
  for(int i=0;i<d;i++)
    cin >> ten.at(i) >> bo.at(i);
  int ans=1000,now=0,te=0;
  for(int i=0;i<(d<<10);i++){
    bitset<10>b=i;
    te=0;
    now=0;
    for(int j=0;j<d;j++){
      if(b.test(j)){
        te+=ten.at(j)*(j+1)*100+bo.at(j);
        now+=ten.at(j);
      }
    }
    if(te<g){
      int n=d-1;
      while(te<g&&n>=0){
        while(b.test(n))
          n--;
        if(n<0)
          break;
        int x=ceil((double(g)-te)/((n+1)*100));
        int a=min(ten.at(n),x);
        te+=a*(n+1)*100;
        now+=a;
        if(a==ten.at(n))
          te+=bo.at(n);
        n--;
      }
    }
    if(te>=g)
      ans=min(ans,now);
  }
  cout << ans << endl;
  return 0;
}