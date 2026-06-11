#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,D,X;
    cin >> N >> D >>X;
    vector<int> vec(N);
    for(int i=0;i<N;i++){
        cin >>vec.at(i);
    }
    int count=0;
    for(int j=0;j<N;j++){
       if(vec.at(j)==1){
           if(N==1){
               count++;
               continue;
           }
           count += D;
           continue;
       }
      count += D/vec.at(j);
      count ++;
      if(D%vec.at(j)==0){
          count--;
      }
    }
     cout << count+X << endl;
}