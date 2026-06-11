
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define vec vector
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

int main()
{
    int n,k,index=1;
    cin >> n>>k;
    
    rep(i,n)
    {
        if(index+k-1 > n)
            break;
        
        index++;
    }
    cout << index-1;
    
    return 0;
}
