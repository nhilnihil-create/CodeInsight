#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    int n ; cin >> n;
    if(n%2==0) n--;
    int yc=0,count=0;
    for(int i = n; i>0;i=i-2){
        yc=0;
        for(int j =i;j>0;j--){
            if(i%j==0) yc++;
        }
        if(yc==8) count++;
    }
    cout << count << endl;
    return 0;
}