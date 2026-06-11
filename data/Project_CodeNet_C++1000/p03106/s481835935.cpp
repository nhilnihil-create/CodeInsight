#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>

using namespace std;

int main(){
    int a,b,k;
  	cin >> a >> b >> k;
    int ans = 101;
    int cnt = 0;
    while (cnt != k){
        ans -= 1;
        if((a % ans == 0)&&(b % ans == 0)){
            cnt += 1;
        }
    }
    cout << ans << endl;
 }
