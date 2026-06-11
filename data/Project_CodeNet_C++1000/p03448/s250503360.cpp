#include<bits/stdc++.h>
using namespace std;
 
int main() {
  	int a,b,c,d;
  	int cnt=0;
  	cin >> a >> b >> c >> d;
    for(int i=0;i<a+1;++i){
    	for(int j=0;j<b+1;++j){
          for(int k=0;k<c+1;++k){
            if(i*500+j*100+50*k==d){
              ++cnt;
            }
          }
        }
    }
 
    cout << cnt << endl;
}