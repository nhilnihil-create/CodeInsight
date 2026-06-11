#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
// O(log N)　keyのある場所を返す。なかったら-1を返す
int search(int key, vector<int> a){
  int right = a.size();
  int left = 0;
  while(right >= left){
    int middle = left + (right - left) / 2;
    if(a[middle] == key) return middle; //keyが入ってる場所を返す
    else if(a[middle] > key) right = middle - 1;
    else if(a[middle] < key) left = middle + 1;
  }
  //なければ-1を返す
  return -1;
}
// O(N^2) babble sort
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  cout << min(a * n , b) << endl;
  return 0;
}