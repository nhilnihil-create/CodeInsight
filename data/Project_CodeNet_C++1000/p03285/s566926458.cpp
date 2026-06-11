#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    for(int i=0; i<=25; i++){
        for(int j=0; j<=14; j++){
            ans = i*4 + j*7;
            if(ans == N){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}

