#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N ;
  
  vector<tuple<string,int,int>> name_score(N);
  
  string name;
  int score;
  int k=1;
  
  for(int i=0;i<N;i++){
    cin >>name>>score;
    name_score[i]=make_tuple(name,-1*score,k);
    k++;
  }
   
  sort(name_score.begin(),name_score.end());
  //reverse(name_score.begin(),name_score.end());
  
  int num;
  for(int i=0;i<N;i++){
    tie(name,score,num)=name_score[i];
    cout << num << endl;
  }
}
  
