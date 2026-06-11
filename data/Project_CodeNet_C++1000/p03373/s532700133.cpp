#include <bits/stdc++.h>
using namespace std;

int main() {
long long A, B, C, X, Y;
cin >> A >> B >> C >> X >> Y;
if(2*C < A + B){
 if(X >= Y){
  if(2*C >= A){
  cout << 2*Y*C + (X - Y)*A << endl;}
  if(2*C < A){
  cout << 2*X*C << endl;}}
 if(X < Y){
  if(2*C >= B){
  cout << 2*X*C + (Y - X)*B << endl;}
  if(2*C < B){
  cout << 2*Y*C << endl;}}}
if(2*C >= A + B){
cout << X*A + Y*B << endl;}}
