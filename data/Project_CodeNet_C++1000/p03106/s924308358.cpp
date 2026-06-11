#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    int a,b ,k; cin >> a>> b>>k;
    int n=max(a,b);
    int count=0,i;
    for (i = n; i >0 ; i--)
    {
        if(a%i==0 && b%i==0) count++;
        if(count == k) break;
    }
    cout << i << endl;
    
    
    return 0;
}