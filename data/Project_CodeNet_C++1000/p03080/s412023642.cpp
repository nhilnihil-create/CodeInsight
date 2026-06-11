#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//for(int i = 0; i<n; i++)


int main()
{
    int n;string s;cin>>n>>s;
    int sum = 0;
    for(int i = 0; i<n; i++) {
        if(s[i] == 'R') sum++;
    }
    cout << (sum > n-sum?"Yes":"No")<<endl;
}