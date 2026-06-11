#include <cstdio>
#include <map>

int as[200005];

void increment(std::map<int,int>& str,int i,int D){
  while(++str[i]==D){
    str[i--]=0;
  }
}

int main(){
  int N;
  scanf("%d",&N);
  bool inc=true;
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    if(as[i]<=as[i-1]){
      inc=false;
    }
  }
  if(inc){
    printf("1\n");
    return 0;
  }
  int low=1,high=N;
  while(high-low>1){
    int mid=(low+high)/2;
    std::map<int,int> str;
    for(int i=1;i<=N;i++){
      if(as[i]<=as[i-1]){
	while(str.size()&&str.rbegin()->first>as[i]){
	  str.erase(str.rbegin()->first);
	}
	increment(str,as[i],mid);
      }
    }
    if(str.count(0)){
      low=mid;
    }else{
      high=mid;
    }
  }
  printf("%d\n",high);
  return 0;
}
