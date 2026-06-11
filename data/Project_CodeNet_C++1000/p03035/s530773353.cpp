#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(void){
    int a,b;

    cin >> a >> b;

    if(a>12){
        cout << b << endl;
    }else if(a>5){
        cout << b/2 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}