#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <limits>
#include <vector>
#define ll long long
#define rep(i,n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int tmp = a;
    if(a%b == 0){
        cout << -1 << endl;
    }
    else
    {
        while(tmp%b == 0){
            tmp += a;
            if(a > 1e18){
                cout << -1 <<endl;
                return 0;
            }
        }
        cout << tmp << endl;
    }
    return 0;
}