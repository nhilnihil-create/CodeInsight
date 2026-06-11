#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(4);
    vector<int> A = {1, 4, 7, 9};
    
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    for (int i = 0; i < A.size(); i++)
    {
        if (a[i] != A[i])
        {
            cout << "NO" << endl;
            return 0;
        }
        
    }
    
    cout << "YES" << endl;
}