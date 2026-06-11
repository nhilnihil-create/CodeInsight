#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//for(int i = 0; i<n; i++)


int main()
{
    int n;
    string a,b,c;cin >> n >> a >> b >> c;
    int sum = 0;
    for(int i = 0; i<n;i++){
        if(a[i] == b[i] && b[i] == c[i])continue;
        else if(a[i] != b[i] && b[i] != c[i] && c[i] != a[i]){
            sum += 2;
        }else sum++;
    }
    cout << sum << endl;
    
}