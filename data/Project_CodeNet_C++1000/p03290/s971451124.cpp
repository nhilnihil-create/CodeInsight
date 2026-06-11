#include<bits/stdc++.h>
using namespace std;

int main(){
  int D, G, min;
  cin >> D >> G;
  min = D * 100;
  
  vector<int> p(10,0),c(10,0);
  for(int i=0;i<D;i++){
    cin >> p.at(i) >> c.at(i);
  }
  
  for(int tmp=0;tmp < (1 << 10);tmp++){
    bitset<10> x(tmp);
    int q=0, score=0;
    
    for(int i=0;i<D;i++){
      if(x.test(i)){
        score += (i+1) * 100 * p.at(i) + c.at(i);
        q += p.at(i);
      }
    }
    
    for(int i=0;i<D;i++){
      if(!(x.test(D-1-i))){
        int count=0;
        while((score < G) && (count < (p.at(D-1-i)))){
          score += 100 * (D-i);
          q++;
          count++;
        }
      }
    }
    
    if(q < min)
      min = q;
  }
  
  cout << min << endl;
}