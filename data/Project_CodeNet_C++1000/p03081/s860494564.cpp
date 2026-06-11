//Exawizerds 2019, problem C
//Reference: submission #4875983.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long int N,Q;
string s;
vector<string> wizerd;

//______________________________________________________________
//This function checks whether if the golem will vanish or not.
//If this function returns 1 or -1, that golem will vanish.
//If this function returns 0, that golem will alive.
int DeadOrAlive(long long int pos){
  char s_temp = s[pos];
  for(int i=0; i<Q; i++){
    if(wizerd[i][0] == s_temp){
      if(wizerd[i][1] == 'L') pos -= 1;
      else pos += 1;
    }
    s_temp = s[pos];
    if(pos < 0) return -1; // position becomes <0, lower limit should be larger than left
    else if(pos > N-1) return 1;//pos become N-1, higher limit should be lower than right
  }
  return 0;
}

//______________________________________________________________
//This function is binary search to determine the lower-bound and the higher bound.
//direction is defined as: lower (left) -> -1, higher (right) -> 1//
long long int BinarySearch(long long int left, long long int right, int direction){
  long long int middle = (left + right)/2;
  if(right - left <= 1) return left;
  if(DeadOrAlive(middle) == -1 && direction == -1) left = middle;
  else if(direction == -1) right = middle;

  if(DeadOrAlive(middle) == 1 && direction == 1) right = middle;
  else if(direction == 1) left = middle;
  return BinarySearch(left, right, direction);
}

//______________________________________________________________
int main(){
  
  cin >> N >> Q;
  cin >> s;
  for(int i=0; i<Q; i++){
    string t_temp, d_temp;
    cin >> t_temp >> d_temp;
    wizerd.push_back(t_temp+d_temp);
  }
  long long int lower_limit = BinarySearch(-1, N, -1);
  long long int higher_limit = BinarySearch(lower_limit, N, 1);
  cout << higher_limit - lower_limit << endl;
  return 0;
}

