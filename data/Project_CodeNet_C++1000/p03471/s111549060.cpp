#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,y;
    cin >> n >> y;
    y /= 1000;
    for(int i=0; i<=y/10; i++){
        for(int j=0; j<=(y-10*i)/5;j++){
            if(i+j+(y-10*i-5*j) == n){
                cout << i<< " "<<  j <<" "<< y-10*i-5*j  << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}