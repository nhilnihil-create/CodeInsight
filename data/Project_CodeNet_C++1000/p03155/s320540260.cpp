/*
g++ -std=c++11 -o2 -Wall AISing2019A.cpp -o .\out\AISing2019A.out
.\out\AISing2019A.out
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
//  freopen("./input/input.txt", "r", stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, h, w;
  cin >> n >> h >> w;
  cout << (n-h+1)*(n-w+1) << "\n";
}
