#include <bits/stdc++.h>
#include <map>
 #define rep(i,n) for(int i=0;i<n;i++)
 using namespace std;
  int main(){
      int n;
      cin >> n;
      int cut=0;
      int g=0;
      int w=0;
      int p=0;
      int y=0;
      rep(i,n){
          char s;
          cin >> s;
         // cout << s << endl;
          if(s=='G' && g==0){
              cut++;
              g++;
          }
            if(s=='P' && p==0){
              cut++;
              p++;
          }
            if(s=='W' && w==0){
              cut++;
              w++;
          }
            if(s=='Y' && y==0){
              cut++;
              y++;
          }
      }
      switch (cut)
      {
      case 3:
      cout << "Three" << endl;
          break;
      
      case 4:
      cout << "Four" << endl;
          break;
      }
  // cout << cut << endl;
      return 0;
  }