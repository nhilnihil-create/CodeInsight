#include<iostream>
using namespace std;
int ctoi(char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
  }
}

int main(){
  int N, A, B, sum_1 = 0;
  string num;
  cin >> N >> A >> B;
  for(int i = 1; i <= N; i++){
    num = to_string(i);
    int sum_2 = 0;
    for(char c : num) sum_2 += ctoi(c);
    if(sum_2 >= A && sum_2 <= B) sum_1 += i;
  }
  cout << sum_1 << endl;
}