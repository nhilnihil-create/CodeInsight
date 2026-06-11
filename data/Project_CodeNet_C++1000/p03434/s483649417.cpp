#include<bits/stdc++.h>
using namespace std;

int main(){
int n,a = 0,b = 0,m;

cin >> n;
vector<int> vec(n);

for(int i = 0;i < n; i++){
  cin >> vec[i];
}

sort(vec.begin(),vec.end());

for(int i = 1;i <= n; i++){
  if(i%2 == 1){
    a += vec[n - i];
  }else{
    b += vec[n - i];
  }
}

cout << a -b << endl;
  return 0;
}