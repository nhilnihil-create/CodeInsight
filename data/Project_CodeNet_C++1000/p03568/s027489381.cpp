#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n; 
    int e = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a %2 == 0) e++;  
    }
    cout << pow(3,n) - pow(2,e) << endl;
    return 0;
}