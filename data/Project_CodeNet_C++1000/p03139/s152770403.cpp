#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    int n,A,B;
    cin>>n>>A>>B;
    cout<<min(A,B)<<' '<<max(0,A+B-n);
    return 0;
}