#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N;
    cin >> N;
    
    for(int i=1;i<=3500;i++){
        for(int j=1;j<=3500;j++){
            if((4*i*j-N*(i+j)) != 0 && (N*i*j)%(4*i*j-N*(i+j)) == 0 && 0<(N*i*j)/(4*i*j-N*(i+j))){
                cout << i << " " << j << " " << (N*i*j)/(4*i*j-N*(i+j)) << endl;
                return 0;
            }
        }
    }
}