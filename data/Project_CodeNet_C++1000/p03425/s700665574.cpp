#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long int count=0;
  cin >> N;
  
  long long int S[5]={0};
  for(int i=0 ; i<N ; i++){
    string name;
    cin >> name;
    switch(name.at(0)){
      case 'M':
        S[0]++;
        break;
      case 'A':
        S[1]++;
        break;
      case 'R':
        S[2]++;
        break;
      case 'C':
        S[3]++;
        break;
      case 'H':
        S[4]++;
        break;
      default:
        break;
    }
   
  }
  
  for(int i=0 ; i<4 ; i++)
    for(int j=i+1 ; j<5 ; j++)
      for(int k=j+1 ; k<5 ; k++)
        count+=S[i]*S[j]*S[k];
      //cout << x << " " << y << " " << z << endl;
  cout << count << endl;
  return 0;
}