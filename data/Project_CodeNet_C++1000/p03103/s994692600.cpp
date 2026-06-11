#include<bits/stdc++.h>
using namespace std;

int main() {
  long long num,buy;
  long long kekka = 0;
  long long yen,hon;
  long long index = 0;
  bool chk = true;
  
  cin >> num >> buy;
  
  vector<pair<long long,long long>> p(num);
  
  for(long long i = 0; i < num; i++){
    cin >> yen >> hon;
    p.at(i) = make_pair(yen, hon);    
  }
  
  sort(p.begin(), p.end());
  
  while(chk == true){
    tie(yen, hon) = p.at(index);
    
    if(buy > hon){
      // 継続
      kekka += yen * hon;
      buy -= hon;
      index++;
    }else{
      kekka += yen * buy;
      // 終わり
      buy = 0;
      chk = false;
    }
  }
  
  cout << kekka;
}
