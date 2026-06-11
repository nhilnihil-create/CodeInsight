#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
 
  for(int i=0;i<n;i++){
    cin >> vec.at(i);
  }
  
  int a,b;
  vector<int> vec_sort(n);
  for(int i=0;i<n;i++){
    vec_sort.at(i) = vec.at(i);
  }
  
  sort(vec_sort.begin(),vec_sort.end());
 
  a = vec_sort.at(n/2-1);
  b = vec_sort.at(n/2);

  for(int i=0;i<n;i++){
    if(vec.at(i) < b){
      cout << b << endl;
    }
    else {cout << a << endl;}
  }
}
  