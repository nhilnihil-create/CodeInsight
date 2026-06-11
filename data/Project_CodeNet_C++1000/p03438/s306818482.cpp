#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){
    
    int N; cin >> N;
    
    vector<long long> a(N),b(N);
    
    for(int i = 0; i < N;i++) cin >> a[i];
    for(int i = 0; i < N;i++) cin >> b[i];
    
    long long A = 0, B = 0;
    
    for(int i = 0; i < N;i++){
        if(a[i] > b[i]) A += a[i] - b[i];
        if(b[i] > a[i]) B += (b[i] - a[i])/2;
    }
    
    if(B >= A)cout << "Yes" << endl;
    else cout << "No" <<endl;
    
}