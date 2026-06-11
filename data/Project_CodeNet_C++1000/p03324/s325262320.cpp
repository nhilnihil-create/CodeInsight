#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long int

void testcase(){
    ll d,n;
    cin>>d>>n;
    if(d == 0){
        if(n == 100){
            cout << n + 1<< "\n";
            return;
        }
        cout << n << "\n";
    }
    else if(d == 1){
        if(n == 100){
            cout << n + 1<< "00\n";
            return;
        }
        cout << n << "00\n";
    }
    else{
        if(n == 100){
            cout << n + 1 << "0000\n";
            return;
        }
        cout << n << "0000\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}
