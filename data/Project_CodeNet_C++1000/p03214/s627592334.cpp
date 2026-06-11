#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> vi(N);
  for(int i=0;i<N;i++){
    cin>>vi.at(i);
  }
  int ave=0;
  for(int i=0;i<N;i++){
    ave+=vi.at(i);
  }
  vector<int> va(N);
  for(int i=0;i<N;i++){
    va.at(i)=N*vi.at(i)-ave;
    if(va.at(i)<0) va.at(i)=(-1)*va.at(i);
  }
  int n=0; int min=va.at(0);
  for(int i=0;i<N;i++){
    if(min>va.at(i)){
      min = va.at(i);
      n=i;
    }
  }
  cout<<n<<endl;
}