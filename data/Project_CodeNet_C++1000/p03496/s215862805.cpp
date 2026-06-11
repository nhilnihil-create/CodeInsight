#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    vector<int> a(N);
    
    int amax = -1000000;
    int amaxp = 0;
    int amin = 1000000;
    int aminp = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        
        if (amax < a[i]) {
            amax = a[i];
            amaxp = i;
        }
        
        if (amin > a[i]) {
            amin = a[i];
            aminp = i;
        }
    }
    
    
    vector<int> x;
    vector<int> y;
    
    if (abs(amax) >= abs(amin)) {
        for (int i = 0; i < N; i++) {
            if (i != amaxp) {
                x.push_back(amaxp+1);
                y.push_back(i+1);
                
            }
            
        }
        
        for (int i = 1; i < N; i++) {
            x.push_back(i);
            y.push_back(i+1);
        }
        
    }else if(abs(amax) < abs(amin)){
        for (int i = 0; i < N; i++) {
            if (i != aminp) {
                
                
                x.push_back(aminp+1);
                y.push_back(i+1);
            }
            
        }
        
        for (int i = N; i > 1; i--) {
            x.push_back(i);
            y.push_back(i-1);
        }
        
    }
    
    
    cout << x.size() << endl;
    
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " " << y[i] << endl;
    }
    
    
    
    
}
