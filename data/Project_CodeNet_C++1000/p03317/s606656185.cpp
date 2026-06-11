#include <bits/stdc++.h>
using namespace std;

int main (){
    int N, K;
    cin >> N >> K;
    vector <int> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];
    if(K-N==0){
        cout << 1 << endl;
    }else if((K-N)%(K-1) == 0){
        cout << (N-K)/(K-1)+1 << endl;
    }else{
        cout << (N-K)/(K-1)+2 << endl;
    }
}