#include <bits/stdc++.h>
using namespace std;
main(){
  int N,x;
  cin >> N >> x;
  int a[N];
  for(int i=0;i<N;i++) cin >> a[i];
  sort(a,a+N);
  int people=0;
  int stock=x;
  int stop=0;
  for(int i=0;i<N;i++){
    if(a[i]<=stock){
      people++;
      stock-=a[i];
    } else {
      stop=i;
      break;
    }
  }
  if(stock>0&&people>0&&stop==0) people--;
  cout << people <<endl;
}