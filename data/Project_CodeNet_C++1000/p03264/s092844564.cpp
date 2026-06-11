#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    
    if(k%2 == 0){
        cout << pow(k/2,2) << endl;
    }
    else{
        cout << pow(k/2,2) + k/2 << endl;
    }
}

