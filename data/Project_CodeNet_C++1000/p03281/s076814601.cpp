#include <iostream>
using namespace std;

int main(){
    int N; 
    cin >> N;

    int ans = 0, div=0;

    if(N%2==0) N--;

    while( N >= 1 ){
        for(int i=1; i<=N; i++){
            if(N%i==0) div++;
        }
        if(div==8){
            ans++;
        } 
        div=0;
        N -= 2;
    }

    cout << ans << endl;

    return 0;
}