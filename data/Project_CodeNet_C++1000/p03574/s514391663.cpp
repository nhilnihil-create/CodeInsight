#include <iostream>
using namespace std;

int main() {
  int H,W,i,j,k,l;
  string S,SC;
  cin >> H >> W;
  for(i=0;i<H;++i){
    cin >> SC;
    S += SC;
  }
  for(i=0;i<H;++i)
    for(j=0;j<W;++j)
      if(S.at(i*W+j)=='#')
        for(k=(i-(i>0)) ; k<(i+1+(i<(H-1))) ; ++k)
          for(l=(j-(j>0)) ; l<(j+1+(j<(W-1))) ; ++l)
            if(S.at(k*W+l)!='#')
              S.at(k*W+l)+=1;
  for(i=0;i<H;++i){
    for(j=0;j<W;++j){
      if(S.at(i*W+j)!='#')
        S.at(i*W+j) += '0' - '.';
      cout << S.at(i*W+j);
    }
    cout << endl;
  }
}
