#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a + b >= c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}