#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int S;
int main(){
    cin >> S;
    if(S%100 <=12 && S % 100>0){
        if(S/100 ==0){
            printf("YYMM\n");
            return 0;
        }else if(S/100 <= 12){
            printf("AMBIGUOUS\n");
            return 0;
        }else{
            printf("YYMM\n");
             return 0;  
        }
        
    }else{
        if(S/100 ==0){
            printf("NA\n");
            return 0;
        }else if(S/100 <= 12){
            printf("MMYY\n");
            return 0;
        }else{
          printf("NA\n");
          return 0;  
        }
    }
}