#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    
    int ans = 0;
    int N = 1;
    int fans = 0; 
    while(N<=A){
        for(int i=1; i<=N; i++){
            if(N%i == 0){
                ans += 1;
            }
        }
        if(ans == 8){
            fans += 1;
        }
        N += 2;
        ans = 0;
    }
    
    cout << fans << endl;
}

