#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>
#include <map>
#include <utility>

using namespace std;

int main(){
    int n ;

    int f = 111;

    cin >> n;

    int ans = 0;

    for(int i = 0; i < 9; i++){
        if(n <= f*(i+1) && n > f*i){
            ans = f*(i+1);
        }
    }

    cout << ans << endl;;



}