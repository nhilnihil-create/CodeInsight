#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);

  for (int i=0; i<N; i++){

    cin>>vec.at(i);
  }
  sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    int a=1;

    for (int i=1; i<N; i++){
    if (vec.at(i-1)>vec.at(i))
    a++;
}

  cout<<a<<endl;
  
}