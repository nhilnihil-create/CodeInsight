#include<bits/stdc++.h>
using namespace std;

bool should_be_swaped_with_the_next(vector<tuple<string, int, int>> list, int index){
  if(get<0>(list.at(index)) < get<0>(list.at(index + 1))){
    return false;
  }else if(get<0>(list.at(index)) > get<0>(list.at(index + 1))){
    return true;
  }else if(get<1>(list.at(index)) < get<1>(list.at(index + 1))){
    return true;
  }else{
    return false;
  }
}

int main(){
  int N;
  cin >> N;
  string city; 
  int score, index;
  bool is_end = false;
  vector<tuple<string, int, int>> list;
  tuple<string, int, int> temp;
  
  for(int i = 0; i < N; i++){
    index = i + 1;
    cin >> city >> score;
    list.push_back(make_tuple(city, score, index));
  }
  
  while(!is_end){
    bool swaped = false;
    for(int i = 0; i < N - 1; i++){
      if(should_be_swaped_with_the_next(list, i)){
        temp = list.at(i);
        list.at(i) = list.at(i + 1);
        list.at(i + 1) = temp;
        swaped = true;
      }
    }
      
    if(!swaped){
      is_end = true;
    }
  }
 
  for(int i = 0; i < N; i++){
    cout << get<2>(list.at(i)) << endl;
  }
}