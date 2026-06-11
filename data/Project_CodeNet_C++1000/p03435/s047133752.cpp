#include <bits/stdc++.h>

using namespace std;
//using ll = long long;

int main() {
    int N = 9;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }
    bool ans =1;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            if (A.at(3*i+j+1)-A.at(3*i+j) != A.at(3*i+j+4)-A.at(3*i+j+3))
            {
                ans = 0;
                break;
            }
            
        }
        for (size_t j = 0; j < 2; j++)
        {
            if (A.at(3*i+j+3)-A.at(3*i+j) != A.at(3*i+j+4)-A.at(3*i+j+1))
            {
                ans = 0;
                break;
            }
            
        }
        
    }
    if(ans) {
    cout << "Yes" << endl;
    } else {
    cout << "No" << endl;
    }
    return 0;
}