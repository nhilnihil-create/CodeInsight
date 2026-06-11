#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
  int seged=0;
  vector<int> szamok5alma;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> seged;
    szamok5alma.push_back(seged);
  }
  seged=0;
  for(int j=0;j<N;j++){
    if(szamok5alma[seged]<szamok5alma[j]){
      seged=j;
    }
  }
  int seged2=0;
  szamok5alma[seged]/=2;
  for(int k=0;k<N;k++){
    seged2+=szamok5alma[k];
  }
  cout << seged2;
	return 0;
}