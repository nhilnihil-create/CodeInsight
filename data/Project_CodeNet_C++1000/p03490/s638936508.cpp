#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    s+='T';
    int x,y;
    cin >> x >> y;
    int n=s.size();
    int direction=0;//0はx方向、1はy方向
    int count=0;
    vector<int> X,Y;
    Y.push_back(0);
    for (int i=0; i<n; i++){
        if (s[i]=='F'){
            count++;
        } else {
            if (direction==0){
                X.push_back(count);
            }else{
                Y.push_back(count);
            }
            count=0;
            direction=1-direction;
        }
    }
    int x_dp[2][16001],y_dp[2][16001];
  for (int i=0;i<2;i++){
    for (int j=0; j<=16000; j++){
      x_dp[i][j]=0;
      y_dp[i][j]=0;
    }
  }

    x_dp[0][8000+X[0]]=1;
    for (int i=1; i<X.size(); i++){
        for (int j=0; j<=16000; j++){
            if (0<=j-X[i] && j-X[i]<=16000){
                if (x_dp[0][j-X[i]]==1)
                    x_dp[1][j]=1;
                }
            if (0<=j+X[i] && j+X[i]<=16000){
                if (x_dp[0][j+X[i]]==1){
                    x_dp[1][j]=1;
                }                                      
            }
        }
        for (int k=0; k<=16000; k++){
            x_dp[0][k]=x_dp[1][k];
            x_dp[1][k]=0;
        }
    }
    y_dp[0][8000]=1;
    for (int i=1; i<Y.size(); i++){
        for (int j=0; j<=16000; j++){
            if (0<=j-Y[i] && j-Y[i]<=16000 ){
              if (y_dp[0][j-Y[i]]==1){
                  y_dp[1][j]=1;
                }
                
            }
            if (0<=j+Y[i] && j+Y[i]<=16000){
                 if (y_dp[0][j+Y[i]]==1){
                    y_dp[1][j]=1;
                }
            }
        }
        for (int k=0; k<=16000; k++){
            y_dp[0][k]=y_dp[1][k];
            y_dp[1][k]=0;
        }
    }
    if (x_dp[0][x+8000]!=0 && y_dp[0][y+8000]!=0){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
