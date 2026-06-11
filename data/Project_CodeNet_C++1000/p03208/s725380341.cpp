#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    int N,K,minv; cin >> N >> K;
    int data[N];
    for(int i=0;i<N;i++) cin >> data[i];
    sort(data,data+N);
    
    for(int i=0;i<N-K+1;i++){
        if(i == 0){ minv = data[i+K-1] - data[i]; }
        else {if(minv > data[i+K-1] - data[i]){ minv = data[i+K-1] - data[i];}}
    }
    
    cout << minv << endl;
} 