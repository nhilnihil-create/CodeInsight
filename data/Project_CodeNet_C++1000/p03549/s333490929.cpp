#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
int main(){
    const int time=1900;
    const int unit=100;
    int n,m;
    cin>>n>>m;
    cout<<(unit*(n-m)+time*m)*pow(2,m)<<endl;
    return 0;
}