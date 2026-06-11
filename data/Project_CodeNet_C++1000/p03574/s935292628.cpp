    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int H,W;
      cin >> H >> W;
      vector<string> S(H);
      vector<vector<int>> Sh(H+2,vector<int>(W+2));//初期化されてる
      int count=0;
      
      for(int i=0;i<H;i++){
        cin >> S.at(i);
      }
      
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if(S.at(i).at(j)=='#'){
            Sh[i][j]++;
            Sh[i][j+1]++;
            Sh[i][j+2]++;
            Sh[i+1][j]++;
            Sh[i+1][j+2]++;
            Sh[i+2][j]++;
            Sh[i+2][j+1]++;
            Sh[i+2][j+2]++;
          }
        }
      }
      
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if(S.at(i).at(j)=='#'){
            cout << S.at(i).at(j);
          }else{
            cout << Sh[i+1][j+1];
          }
        }
        cout << endl;
      }
      
    }