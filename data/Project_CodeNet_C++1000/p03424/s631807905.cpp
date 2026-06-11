#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N,Y=0;
    cin>>N;
    for(int i=0;i<N;i++){
      string c;
      cin>>c;
      if((c=="Y"))Y++;
    }
    if(Y>0)cout<<"Four"<<endl;
    else cout<<"Three"<<endl;
    return 0;
}