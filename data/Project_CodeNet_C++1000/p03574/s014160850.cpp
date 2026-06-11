#include <iostream>
#include <vector>
#include <string>
using namespace std;

char f(vector<string> S,int i,int j){
  int num = 0;
  int H = S.size(), W = S.at(0).size();
  if(S.at(i).at(j)=='#'){
    return '#';
  }else{
    if(S.at(i).at(j-(j>0))=='#') num++;
    if(S.at(i).at(j+(j<W-1))=='#') num++;
    if(i>0&&S.at(i-1).at(j)=='#') num++;
    if(i>0&&j>0&&S.at(i-1).at(j-1)=='#') num++;
    if(i>0&&j<(W-1)&&S.at(i-1).at(j+1)=='#') num++;
    if(i<(H-1)&&S.at(i+1).at(j)=='#') num++;
    if(i<(H-1)&&j>0&&S.at(i+1).at(j-1)=='#') num++;
    if(i<(H-1)&&j<(W-1)&&S.at(i+1).at(j+1)=='#') num++;
    char Num = '0'+num;
    return Num;
  }
}
    
int main(){
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  for(int i=0; i<H; i++){
    cin >> S.at(i);
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cout << f(S,i,j);
    }
    cout << endl;
  }
  return 0;
}