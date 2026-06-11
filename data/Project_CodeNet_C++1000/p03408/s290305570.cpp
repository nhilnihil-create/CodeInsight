#include<iostream>
#include<string>
using namespace std;
int main(void){
  //入力部
  int N;
  cin >> N;
  string s[N];
  for (int i=0;i<N;i++){
    cin >> s[i];
  }
  int M;
  cin >> M;
  string t[M];
  for (int i=0;i<M;i++){
    cin >> t[i];
  }
  //処理部
  int count = 0;
  for (int i=0;i<N;i++){
    int num = 0;
    for (int j=0;j<N;j++){
      if (s[i] == s[j]) num++;
    }
    for (int k=0;k<M;k++){
      if (s[i] == t[k]) num--;
    }
    count = (num > count) ? num : count;
  }
  cout << count << endl;
  return 0;
}