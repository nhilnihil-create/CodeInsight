#include<bits/stdc++.h>
using namespace std;
pair<pair<string,int>,int> t[110];//なぜint mainよりも前に宣言？
int main(){
  int N;
  cin>>N;
  
  for(int i=0;i<N;i++){
    int score;
    string name;
    cin>>name>>score;
    t[i]=make_pair(make_pair(name,score*(-1)),i+1);
  }
  
  //sort(t.begin(),t.end());　　なぜこれじゃダメ？
  std::sort(t,t+N);
  for(int i=0;i<N;i++){
    cout<<t[i].second<<endl;
  }
}
  
 
/*ここから駄目だったやつ
tuple<string,int,int> t[110];　　tuple型でやろうとした
 for(int i=0;i<N;i++){
    int score;
    string name;
    cin>>name>>score;
    t[i]=make_tuple(name,score*(-1),i+1);
  }
  std::sort(t,t+N);
  for(int i=0;i<N;i++){
    cout<<t[i].third<<endl;　tupleはこういう風に参照できない？
  }
}
  */