#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

long long MOD = 1000000007;

int main(){
    double n, m, d;
    cin >> n >> m >> d;
    double ans=0.0;
    if(d==0){
        ans=n;
    }else{
        ans=min(n,2*d)+max(0.0,(n-2*d))*2;
    }
    ans=ans*(m-1)/n/n;
    cout << setprecision(10) << ans << endl;
}