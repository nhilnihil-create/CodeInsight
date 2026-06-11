#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
  int N,M;
  int K,like;
  cin >> N>>M;
  set<int> foods,food,food_tmp;
  cin >> K;
  for (int i=0;i<K;i++) {
    cin >> like;
    foods.insert(like);
  }
  for(int i=1;i<N;i++){
    cin >> K;
    food.clear();
    for (int j=0;j<K;j++){
      cin >> like;
      food.insert(like);
    }
    food_tmp.clear();
    set_intersection(foods.begin(),foods.end(),
                     food.begin(),food.end(),
                     inserter(food_tmp,food_tmp.end()));
    foods=food_tmp;
  }

  cout << foods.size();
}