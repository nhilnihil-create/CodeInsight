#include<bits/stdc++.h>
using namespace std;

int main(){
  int D;
  int G;
  cin >> D >> G;
  vector<int> p(D);
  vector<int> c(D);
  
  int max_count = 0;
  
  for(int i=0;i<D;i++){
    cin >> p.at(i) >> c.at(i);
    max_count += p.at(i);
  }
  
  int answer_count = max_count;
  
  for(int bit=0;bit<(1<<D);bit++){
    bitset<10> s(bit);
    int sum = 0;
    int count = 0;
    for(int i=D-1;i>=0;--i){
      if((bit>>i)&1){
        for(int j=0;j<p.at(i);++j){
          sum+=100*(i+1);
          count++;
          if(j+1==p.at(i)) sum += c.at(i);
          if((sum>=G)&&(count<=answer_count)){
              answer_count = count;
              break;
          }
        }    
      }
    }
  }
  
  cout << answer_count << endl;

  
}