#include <bits/stdc++.h>
using namespace std;

int main(){
string S;
cin >> S;
int num = 700;
for(int i=0;i<3;i++){
  if(S.at(i)=='o'){
    num+=100;
  }
}
cout << num << endl;
 return 0;

}