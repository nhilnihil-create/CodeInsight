#include<iostream>
#include<vector>
using namespace std;

int main(){
  int l; cin >> l;
  int copy=l;
  int i=0,s=0;
  vector<int> v;
  while(l){
    v.push_back(l%2);
    if(l%2)s++;
    l/=2;
  }
  s--;
  int len=v.size();
  printf("%d %d\n",len,s+2*(len-1));
  s=1;
  for(int i=0;i<len-1;i++){
    printf("%d %d %d\n%d %d %d\n",i+1,i+2,0,i+1,i+2,s);
    if(v.at(i)){
      copy-=s;
      printf("%d %d %d\n",i+1,len,copy);
    }
    s*=2;
  }
}
