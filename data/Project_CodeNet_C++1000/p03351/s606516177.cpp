#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    string s;
    int d;
    int v[3];
    rep(i,3){
       cin >> v[i];
    }
    cin >> d;
    if (max(v[0],v[2])-min(v[0],v[2]) <= d){
       cout << "Yes" << endl;
       return 0;
    }
    if (abs(v[0]-v[1]) <= d  && abs(v[1]-v[2]) <= d ) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;

}