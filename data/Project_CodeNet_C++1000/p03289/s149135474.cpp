#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >>S;
    int count=0;
    if(S.at(0)=='A'){
     if(islower(S.at(1))){
      for(int i=2;i<S.size()-1;i++){
          if(S.at(i)=='C'){
              count ++;
          }
          else if(isupper(S.at(i))){
              cout <<"WA"<<endl;
              return 0;
          }
      }
     }
     else{
         cout<<"WA"<<endl;
         return 0;
     }
    }
    else{
        cout <<"WA"<<endl;
        return 0;
    }
    if(islower(S.at(S.size()-1))){
        if(count==1){
        cout <<"AC"<<endl;
        }
    else{
        cout <<"WA"<<endl;
        return 0;
    }    
    }
    else{
        cout <<"WA"<<endl;
        return 0;
    }
}