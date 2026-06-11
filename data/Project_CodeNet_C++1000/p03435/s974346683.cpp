#include <iostream>

#define Nfori(N) for(int i=0;i<N;i++)
#define Nforj(N) for(int j=0;j<N;j++)
using namespace std;

int main(){
  	int c[3][3];
  	Nfori(3){
      	Nforj(3) cin >> c[i][j];
    }
  	int difi[2][3];
  	int difj[3][2];
  	Nfori(2){
      	Nforj(3){
          	difi[i][j]=c[i][j]-c[i+1][j];
          	difj[j][i]=c[j][i]-c[j][i+1];
        }
    }
  	string ans = "Yes";
  	Nfori(2){
      	if(difi[i][0]!=difi[i][1] || difi[i][1]!=difi[i][2] || difj[0][i]!=difj[1][i] || difj[1][i]!=difj[2][i]){
          	ans="No";
        }
    }
  	cout << ans << endl;
}