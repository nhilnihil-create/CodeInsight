#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  cin>>N;
  if(N==3){
    cout<<2<<endl;
    cout<<5<<endl;
    cout<<63<<endl;
    return 0;
  }
  // cout<< N - 15000 << endl;
  int aho = max(0, N - 15000);
  if(N&1) aho++;
  int cnt3 = max(2, aho);
  int cnt2 = N - cnt3;
 //  cout<<aho<<' '<<cnt3<<' '<<cnt2<<endl;
  int tmp3=3;
  int tmp2=2;
  for(int i=0;i<cnt3;i++){
    cout<<tmp3<<endl;
    tmp3+=6;
  }
  int sum=0;
  for(int i=0;i<cnt2;i++){
    if(i==cnt2-1){
      if( (tmp2+sum)%3 == 1){
        tmp2+=2;
      }else if( (tmp2+sum)%3 == 2){
        tmp2+=4;
      }
    }
    cout<<tmp2<<endl;
    sum += tmp2;
    tmp2+=2;
  }
}