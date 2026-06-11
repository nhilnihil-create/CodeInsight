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
    int n,t ,c, tmp ,ans;
    cin >> n >> t;
    vector<int> v(n , 3000);
    for (int i = 0 ;i < n ; i++){
        cin >> c >> tmp;
        if (tmp <= t){
            v.at(i) = c;
        
        }
    }
    ans =  *min_element(v.begin() , v.end());
    if (ans != 3000){
        cout <<ans << endl;
    }
    else{
        cout << "TLE" << endl;
    }
}
