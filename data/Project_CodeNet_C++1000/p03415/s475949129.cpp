#include <bits/stdc++.h>
using namespace std;

int main() {
 vector<string> c(3);
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cin >> c[i][j];
  
   for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(i == j){
  		cout << c[i][j];
        }
	 cout << endl;
}