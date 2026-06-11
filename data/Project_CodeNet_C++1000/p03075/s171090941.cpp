#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n = 5;
    int antenas[n];
    int k,tmp;
    for(int i = 0;i < n;i++){
       cin >> tmp;
       antenas[i] = tmp;
    }
    cin >> k;
    int t = 0;
    for(int i = 0;i < n;i++){
      for(int j= i+1;j < n;j++){
        if(k < (antenas[j]-antenas[i])){
            t = 1;
            break;
        }
      }
      if(t == 1)break;
    }
    

    if(t == 1){
        cout << ":(" << endl;
    }else{
        cout << "Yay!" << endl;
    }

}