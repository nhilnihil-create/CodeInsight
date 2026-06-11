#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long int count=0;
  cin >> N;
  
  vector<char> MARCH={'M', 'A', 'R', 'C', 'H'};
  map<char, long long int> m;
  
  for(int i=0 ; i<N ; i++){
    string name;
    cin >> name;
    if(name[0]=='M' || name[0]=='A' || name[0]=='R' || name[0]=='C' || name[0]=='H')
      m[name[0]]++;
  }
  
  for(int i=0 ; i<4 ; i++)
    for(int j=i+1 ; j<5 ; j++)
      for(int k=j+1 ; k<5 ; k++)
        count+=m[MARCH[i]]*m[MARCH[j]]*m[MARCH[k]];
      //cout << x << " " << y << " " << z << endl;
  cout << count << endl;
  return 0;
}