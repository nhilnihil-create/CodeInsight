#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,hcf,lcm;
    cin>>N;
    for(int i = 1; i <= 2 && i <=N; i++) {
        if (2% i == 0 && N % i == 0) {
            hcf = i;
        }
    }
    lcm=(N*2)/hcf;
    cout<<lcm;
}
