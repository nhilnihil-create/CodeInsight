#include <bits/stdc++.h>
using namespace std;

int i=2;

void R(unsigned long long int a,unsigned long long int b,int n){
    
    if(n < 2){
        cout << 1 << endl;
        return;
    }
    else{
        unsigned long long int l = b;
        unsigned long long int r = a+b;
        
        if(i == n){
            cout << r << endl;
            return;
        }
        else{
            i++;
            R(l,r,n);
        }
    }

}

int main(void){
  
  int N;
  cin >> N;
  R(2,1,N);
}