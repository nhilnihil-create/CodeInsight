#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct DATA{

  string name;
  int point;
  int num;
  
  bool operator<(const DATA& another) const{
  
    if(name==another.name){
    
      return point>another.point;
    }
    else return name<another.name;
  }
};
int main(){

  int N;
  cin>>N;
  vector<DATA>data(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>data[i].name>>data[i].point;
    data[i].num=i+1;
  }
  sort(data.begin(),data.end());
  for(int i=0;i<=N-1;i++){
  
    cout<<data[i].num<<endl;
  }
  return 0;
}