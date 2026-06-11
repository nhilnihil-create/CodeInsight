#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector < int > v;
map < int, int > mp;

int main()
{

    bool vis[110];
    int M,k;
    cin >> M >> k;
    int Xor = 0;
    for(int i = 0; i<(1 << M); i++)
    {
        v.push_back(i);
        v.push_back(i);
        if(i != k)  Xor^=i;
    }
    if(k == 0){
        for(auto it : v)  cout << it << " ";
        return 0;
    }
    if(Xor == k){
        int n = (1 << (M + 1));
        v[n/2 - 1] = k;
        int j = 0;
        for(int i = 0;i<n/2 - 1;i++){
            if(j == k)  j++;
            v[i] = j;
            v[n - 2 - i] = j;
            j++;
        }
        v[n - 1] = k;
        for(auto it : v)  cout << it << " ";
        return 0;
    }
    cout << -1;
    return 0;
}
