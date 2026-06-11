#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<cmath>
#include<vector>
#include<map>
#include<random>
using namespace std;

int main(){
    int n;cin >> n;
    int l[n];
    int t = 0;
    int tmp = 0;
    int id = 0;
    for(int i = 0;i < n;i++){
        cin >> l[i];
        if(tmp < l[i]){
            tmp = l[i];
            id = i;
        }
    }
    for(int i = 0;i < n;i++){
        if(i == id)continue;
        t += l[i];
    }

    if(tmp < t){
        cout << "Yes" << endl;
    }else{cout << "No" << endl;}

}