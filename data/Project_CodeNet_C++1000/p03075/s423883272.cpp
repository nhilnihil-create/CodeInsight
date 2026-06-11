#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v(5,0); 
    int k;
    bool flag = true;
    for(int i = 0;i< 5;i++ ){
        cin >> v.at(i) ;
    }
    cin >> k ;
    for (int i = 0;i < v.size();i++){
        for (int j = 0;j < v.size() ; j++){
          // cout << abs(v.at(i) - v.at(j)) << endl;
            if(abs(v.at(i) - v.at(j)) > k){
                flag = false;
                break;
                
            }
        }
    }
    if (flag){
        cout << "Yay!" << endl;
    }
    else{
        cout << ":(" << endl;
    }
}


