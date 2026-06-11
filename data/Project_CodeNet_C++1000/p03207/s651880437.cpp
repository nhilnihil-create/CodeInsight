#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>
#include <stdlib.h>
# include <map>

using namespace std;

int main(){
    int n,tmp2;
    int tmp= 0;
  	int ans = 0;
    cin >> n;
    for(int i = 0;i< n;i++){
        cin >> tmp2;
        ans += tmp2;
        if(tmp < tmp2){
            tmp = tmp2;

        }
    }
    cout << ans -tmp/2;
}
