//#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  string n_words[N];
  for(int i = 0; i < N; i++) {
    cin >> n_words[i];
  }
  cin >> M;
  string m_words[M];
  for(int i = 0; i < M; i++) {
    cin >> m_words[i];
  }
  
  int point = 0;
  string target = "";
  for(int i = 0; i < N; i++) {
    target = n_words[i];
    int point_dum = 0;
    for(int j = 0; j < N; j++) {
      if(target == n_words[j]) {
        point_dum++;
      }
    }
    for(int k = 0; k < M; k++) {
      if(target == m_words[k]) {
        point_dum--;
      }
    }
    if(point_dum > point) {
      point = point_dum;
    }
  }
  cout << point << endl;
}
