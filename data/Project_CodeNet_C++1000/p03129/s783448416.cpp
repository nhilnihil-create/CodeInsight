#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cfenv>
using ll = unsigned long long;
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int m=(k-1)*2+1;
    if(m<=n){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}