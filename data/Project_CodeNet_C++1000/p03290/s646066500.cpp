#include <bits/stdc++.h>
using namespace std;

int Answer(int Goal, vector<int> Prob, vector<int> Comp){
  int D2 = Prob.size();
  
  if (Goal <= 0) {
    return 0;
  }
  
  for (int i = 0; i < D2; i++) {
    if (Comp.at(i) != 0) {
      
      vector<int> Prob2 = Prob;
      vector<int> Comp2 = Comp;
      Prob2.at(i) -= 1;
      Comp2.at(i) = 0;
      vector<int> Prob3 = Prob;
      vector<int> Comp3 = Comp;
      Prob3.at(i) = 0;
      Comp3.at(i) = 0;
      int Compscore = Prob.at(i)*100*(i+1) + Comp.at(i);
      
      return min(Answer(Goal,Prob2,Comp2),Answer(Goal-Compscore,Prob3,Comp3)+Prob.at(i));
    }
  }
  
  int S = 0;
  int A = 0;
  for (int i = D2-1; i >= 0; i--) {
    for (int j = 0; j < Prob.at(i); j++) {
      S += (i+1) * 100;
      A++;
      if (S >= Goal) {
        return A;
      }
        
    }
  }
  
  return 10000;
  
}

int main() {
  int D, G;
  cin >> D >> G;
  
  vector<int> problem(D);
  vector<int> complete(D);
  for (int i = 0; i < D; i++) {
    cin >> problem.at(i) >> complete.at(i);
  }
  
  cout << Answer(G,problem,complete) << endl;
  
  return 0;
}
