#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    string N ;
    cin >> N ;
    int n = 4 ;
    int cnt = 0 ;
    for(int i = 0 ; i< 4 ;i++){
        if(N[i] == '2'){
            cnt++ ;
        }
    }
    cout << cnt << endl;
  
}