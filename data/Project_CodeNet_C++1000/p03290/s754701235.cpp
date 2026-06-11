#include <bits/stdc++.h>
using namespace std;
int main(){
  int d, g, ans=100000000;
  cin >> d >> g;
  int p[10]={0}, c[10]={0};
  for(int i=0; i<d; i++)
    cin >> p[i] >> c[i];
  for(int tmp=0; tmp<(1<<10); tmp++){
    bitset<10> s(tmp);
    int num=0, sum=0;
    for(int i=0; i<d; i++){
      if(s[i]==1){
	num +=p[i];
	sum += c[i]+100*(i+1)*p[i];
      }
    }
    if(sum>=g){
      if(num<ans) ans = num;
      continue;
    }
    for(int i=d-1; i>=0; i--){
      if(s[i]==0){
	if(sum+100*(i+1)*p[i]>=g){
	  num+=ceil((g-sum)*1.0/(100*(i+1)));
	  if(num<ans) ans = num;
	  break;
	}
	else{
	  sum+=100*(i+1)*p[i];
	  num+=p[i];
	}
      }
    }
  }
  cout << ans;
  return 0;
}