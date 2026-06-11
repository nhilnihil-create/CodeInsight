#include <bits/stdc++.h>
using namespace std;
int main(void){
 
 int N,c = 0,max=0;
 cin >> N;
 for(int i=0;i<N;i++){
     int l_i;
     cin >> l_i;
     c += l_i;
     if(max < l_i) max = l_i;
     
 }
 c -= max;

 if(max < c){
     cout << "Yes" <<endl;
 }
 else{
     cout << "No" <<endl;
 }

}