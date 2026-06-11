#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> a(N),b(N),c(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  for(int i=0;i<N;i++){
    cin >> b.at(i);
    c.at(i)=b.at(i)-a.at(i);
  }
  while(1){
    sort(c.begin(),c.end());
    if(c.front()>=0){
      cout << "Yes" << endl;
      return 0;
    }else if(c.back()<=0){
      cout << "No" << endl;
      return 0;
    }
    int b=c.back();
    int f=c.front();
    if(c.back()>=-c.front()*2){
      c.back()+=c.front()*2;
      c.front()=0;
    }else{
      int64_t x=c.back()+c.front()*2;
      if(x%2==0){
        c.front()=x/2;
        c.back()=0;
      }else{
        c.front()=x/2-1;
        c.back()=1;
      }
    }
    if((c.back()==b)&&(c.front()==f)){
      cout << "No" << endl;
      return 0;
    }
  }
  return 0;
}
