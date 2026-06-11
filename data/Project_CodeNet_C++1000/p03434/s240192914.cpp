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

    int a=vec.at(0);

    for (int i=1; i<N; i++){
    if (i%2==0)
    a+=vec.at(i);
    else
    a-=vec.at(i);
}

  cout<<a<<endl;
  
}