#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;

int main(){
    int a,b;cin>>a>>b;
    if(b%a==0)cout<<a+b;
    else cout<<b-a;
    
}