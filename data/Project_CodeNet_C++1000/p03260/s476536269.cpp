#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int a,b;cin >> a >> b;
    for(int i = 1;i <= 3;i++){
        if((a*b*i)%2==1){
            cout << "Yes" << endl;
            break;
        }
        if(i==3)cout << "No" << endl;
    }
}