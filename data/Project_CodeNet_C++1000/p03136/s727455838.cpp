#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N=0;
  vector<int> szamok;
  int seged=0;
  cin>>N;
  for(int i=0;i<N;i++){
    cin >>seged;
    szamok.push_back(seged);
  }
  
  int maxi=0;
  int max=szamok[0];
  for(int i=1; i<N; i++){
    if(max<szamok[i]){
      max=szamok[i];
      maxi=i;
    }
  }

  int osszeg=0;
  for(int i=0; i<N; i++){
    if(i!=maxi){
      osszeg+=szamok[i];
    }
  }
  
  if(osszeg>max){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
	return 0;
}
