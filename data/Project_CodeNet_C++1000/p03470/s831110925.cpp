#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin >> n;
vector<int> vec(n);

for(int i = 0;i < n; i++){
  cin >> vec[i];
}

sort(vec.begin(), vec.end());
vec.erase(unique(vec.begin(), vec.end()), vec.end());

cout << vec.size() << endl;
  return 0;
}