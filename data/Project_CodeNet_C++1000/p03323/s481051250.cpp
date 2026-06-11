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
    int a,b;
    cin>>a>>b;
    if(a <= 8 && b <= 8){
        cout << "Yay!";
    }    
    else{
        cout << ":(";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}
