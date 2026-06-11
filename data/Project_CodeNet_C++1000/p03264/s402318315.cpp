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
int k;
cin >> k;
if (k%2 == 0){
   cout << (k/2)*(k/2) << endl;
}

else{
    cout << ((k-1)/2)*(((k-1)/2)+1) << endl;
}
}