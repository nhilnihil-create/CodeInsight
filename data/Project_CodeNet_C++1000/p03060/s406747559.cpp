#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>

using namespace std;

int main(){
    int n;
    int ans;
    cin >> n;
    vector<int> v(n);
    vector<int> c(n);
    for(int i = 0;i<n ;i++){
        cin >> v.at(i);
    }

    for(int i = 0;i<n ;i++){
        cin >> c.at(i);
    }

    for(int i = 0;i<n ;i++){
        if(v.at(i) - c.at(i) > 0){
            ans += (v.at(i) - c.at(i));
        }
    }
    cout << ans << endl;
 } 
