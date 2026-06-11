#include<bits/stdc++.h>
using namespace std;
int main(void){

  char a,b,c;
  int count=0;
  cin >> a >> b >> c;
  char num[3]={a,b,c};
for(int i=0;i<3;i++){
	if(num[i] == '1'){
      count++;
    }
      
}
  
cout << count << endl;

}