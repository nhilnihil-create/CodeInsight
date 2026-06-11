#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, A[4], sum = 0;
    string S;
    cin >> N;
    for(int n = 0; n < N; n++) {
        cin >> S;
        if(S == "P")
            A[0]++;
        else if(S == "W")
            A[1]++;
        else if(S == "G")
            A[2]++;
        else if(S == "Y")
            A[3]++;
    }
    
    for(int i = 0; i < 4; i++)
        if(!A[i])
            sum++;
    
    if(sum == 1)
        cout << "Three" << endl;
    else if(!sum)
        cout << "Four" << endl;
}