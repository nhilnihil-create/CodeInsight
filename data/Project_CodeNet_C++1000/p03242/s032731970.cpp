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
    string n;
    cin >> n;
    for(int i = 0; i < n.length() ; i++){
        if (n[i] == '1'){
            n[i] = '9';
        }
        else if(n[i] == '9'){
            n[i] = '1';
        }
        
    }
    cout << n << endl;
}
