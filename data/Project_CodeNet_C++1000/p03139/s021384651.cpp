#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    int k;
    if(a+b>n){
        k = a+b-n;
    }else{
        k = 0;
    }
    cout << min(a,b) << ' ' << k;
}
