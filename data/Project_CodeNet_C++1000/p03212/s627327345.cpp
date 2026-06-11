#include <bits/stdc++.h>
using namespace std;
int64_t m, ct=-1;
void f(int64_t n){
  if(n<=m) ct++;
  else return;
  f(10*n+3);
  f(10*n+5);
  f(10*n+7);
}
void g1(int64_t n){
  if(n<=m) ct--;
  else return;
  g1(10*n+3);
  g1(10*n+5);
}

void g2(int64_t n){
  if(n<=m) ct--;
  else return;
  g2(10*n+3);
  g2(10*n+7);
}

void g3(int64_t n){
  if(n<=m) ct--;
  else return;
  g3(10*n+5);
  g3(10*n+7);
}

void h1(int64_t n){
  if(n<=m) ct++;
  else return;
  h1(10*n+3);
}

void h2(int64_t n){
  if(n<=m) ct++;
  else return;
  h2(10*n+5);
}

void h3(int64_t n){
  if(n<=m) ct++;
  else return;
  h3(10*n+7);
}

int main() {
  cin >> m;
  f(0);
  g1(0);
  g2(0);
  g3(0);
  h1(0);
  h2(0);
  h3(0);
  cout << ct;
  return 0;
}
