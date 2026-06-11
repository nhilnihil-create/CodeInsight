#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int A, B, C, D, E;
    int k;
    cin >> A >> B >> C >> D >> E >> k;
    
    vector<int> dist;
    dist.push_back(abs(A - B)); 
    dist.push_back(abs(A - C)); 
    dist.push_back(abs(A - D)); 
    dist.push_back(abs(A - E)); 
    dist.push_back(abs(B - C)); 
    dist.push_back(abs(B - D)); 
    dist.push_back(abs(B - E)); 
    dist.push_back(abs(C - D)); 
    dist.push_back(abs(C - E)); 
    dist.push_back(abs(D - E)); 

    bool p = true; 
    for (size_t i = 0; i < dist.size(); i++) {
        if (dist[i] > k)
            p = false;
    }
    cout << (p ? "Yay!" : ":(") << '\n';

    return 0;
}
