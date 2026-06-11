#include "./bits/stdc++.h"
using namespace std;

float N,K;

int main(){
    int a;
    cin >> N >> K;
    vector<int> A;
    for(int i=0;i<N;i++){
        cin >> a;
        A.push_back(a);
    }
    
    int g=1;
    while (true){
        if(N<=K+(K-1)*(g-1)) break;
        else g++;
    }
    cout << g << endl;
    
    return 0;
}