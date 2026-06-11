#include <bits/stdc++.h>
using namespace std;


int c1, c2,c3,c4,c5,c6,c7,c8,c9;
int sum_1,sum_2,sum_3;
int main(){
  cin>>c1>>c2>>c3;
  cin>>c4>>c5>>c6;
  cin>>c7>>c8>>c9;
  sum_1 = c1+c5+c9;
  sum_2 = c2+c6+c7;
  sum_3 = c3+c4+c8;
  if((sum_1 == sum_2)&&(sum_2 == sum_3)&&(sum_3 == sum_1)){
    cout<< "Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
