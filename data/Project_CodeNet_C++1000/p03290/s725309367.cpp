#include <bits/stdc++.h>
using namespace std;

int atscore(vector<int> p, vector<int> c, int G ){
  vector<int> num(p.size(),10000);
  int n;
  /* cout << "atscore(p, c, " << G << "){" << endl;
  for(int i = 0; i < p.size(); i++)
    cout << p.at(i) << ", ";
    cout << endl;*/
  if(G <= 0) n = 0;
  else{
    for(int i = 0; i < p.size(); i++){
      if(p.at(i) == 0) continue;
      else if(G>p.at(i)*(i+1)*100){
	int tmp = p.at(i);
	p.at(i) = 0;
	num.at(i) = atscore(p, c, G-tmp*(i+1)*100 - c.at(i)) + tmp;
	p.at(i) = tmp;
      }else{
	num.at(i) = (double)G/((i+1)*100) + 0.9999;
      }
    }
    sort(num.begin(),num.end());
    n = num.at(0);
  }
  /*for(int i = 0; i < p.size(); i++)
    cout << num.at(i) << " :";
  cout << endl;
  cout << n << endl;
  cout << "}atscore(p, c, " << G << ")" << endl;*/
  return n;
}

int main(){
  int D, G, i;
  cin >> D >> G;
  vector<int> p(D) , c(D);
  
  for(i = 0; i < D; i++){
    cin >> p.at(i) >> c.at(i);
  }
  cout << atscore(p,c,G) << endl;
}
