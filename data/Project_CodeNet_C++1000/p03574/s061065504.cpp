#include <bits/stdc++.h>
using namespace std;

int countBomb(vector<string> &g, int i, int j) {
  int count = 0;
  if(g.at(i - 1).at(j - 1) == '#') count++;  
  if(g.at(i - 1).at(j - 0) == '#') count++;  
  if(g.at(i - 1).at(j + 1) == '#') count++;  

  if(g.at(i - 0).at(j - 1) == '#') count++;  

  if(g.at(i - 0).at(j + 1) == '#') count++;  

  if(g.at(i + 1).at(j - 1) == '#') count++;  
  if(g.at(i + 1).at(j - 0) == '#') count++;  
  if(g.at(i + 1).at(j + 1) == '#') count++;
  return count;
}

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> ground(H + 2);
  for(int i = 0; i < W + 2; i++) {
    ground.at(0).push_back('.');
    ground.at(H + 1).push_back('.');
  }
  for(int i = 1; i < H + 1; i++) {
    string Sx;
    cin >> Sx;
    
    stringstream ss;
    ss << '.' << Sx << '.';
    ground.at(i) = ss.str();
  }

  for(int i = 1; i < H + 1; i++) {
    for(int j = 1; j < W + 1; j++) {
      if(ground.at(i).at(j) == '.') {
        int b = countBomb(ground, i, j);
        stringstream ss;
        ss << b;
        ground.at(i).at(j) = ss.str().at(0);
      }
    }
  }
  
  for(int i = 0; i < H + 2 ; i++) {
    if (i == 0 || i == H + 1) continue;
    
	for(int j = 1; j < W + 1; j++) {
      cout << ground.at(i).at(j);
    }
    cout << endl;
  }
}
