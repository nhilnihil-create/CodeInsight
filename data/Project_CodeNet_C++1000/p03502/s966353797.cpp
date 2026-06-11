#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int N,n,ans=0;
    cin >> N;
    n = N;
    while(N>0){
        ans += N%10;
        N /=10;        
    }
    if(n%ans==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}
