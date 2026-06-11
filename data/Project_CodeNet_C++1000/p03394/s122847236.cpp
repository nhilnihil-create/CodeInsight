#include<bits/stdc++.h> 
using namespace std; 
 
int main() { 
        int N; 
        cin >> N; 
        if (N == 3) { 
                cout << "2 5 63" << endl; 
                return 0; 
        } 
        vector<int> a; 
        a.push_back(2); a.push_back(4); 
        a.push_back(3); a.push_back(9); 
        for(int i = 1; i * 6 + 4 <= 30000 && a.size() < N - 1; ++i) { 
                a.push_back(i * 6 + 2); 
                a.push_back(i * 6 + 4); 
        } 
        for(int i = 1; i * 12 + 9 <= 30000 && a.size() < N - 1; ++i) { 
                a.push_back(i * 12 + 3); 
                a.push_back(i * 12 + 9); 
        } 
        for(int i = 6; i <= 30000 && a.size() < N; i += 6) { 
                a.push_back(i); 
        } 
        sort(a.begin(), a.end()); 
        for(int i = 0; i < N; ++i) { 
                cout << a[i] << (i == N - 1 ? "\n" : " "); 
        } 
        return 0; 
} 
