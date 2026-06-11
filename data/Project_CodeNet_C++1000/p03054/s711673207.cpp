#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,N;
  cin >> H >> W >> N;
  int sr,sc; cin >> sr >> sc;
  sr--; sc--;
  string S,T;
  cin >> S >> T;
  
  //高橋は方向を1つに絞ってやればよい
  //（取り除ける列が存在したとき、取り除いた方向以外は、縦横が違うか、それを打ち消してるか）
  //青木がそれに対抗できるか（逆に動かし続けられるか）
  int tr,tc;
  bool f=false;
  
  //L
  tc=sc;
  for(int i=0; i<N; i++){
    if(S[i]=='L') tc--;
    if(tc<0) f=true;
    if(T[i]=='R') tc=min(tc+1,W-1);
  }
  
  //R
  tc=sc;
  for(int i=0; i<N; i++){
    if(S[i]=='R') tc++;
    if(tc>=W) f=true;
    if(T[i]=='L') tc=max(tc-1,0);
  }
  
  //U
  tr=sr;
  for(int i=0; i<N; i++){
    if(S[i]=='U') tr--;
    if(tr<0) f=true;
    if(T[i]=='D') tr=min(tr+1,H-1);
  }
  
  //D
  tr=sr;
  for(int i=0; i<N; i++){
    if(S[i]=='D') tr++;
    if(tr>=H) f=true;
    if(T[i]=='U') tr=max(tr-1,0);
  }
  
  cout << (f?"NO":"YES") << endl;
}