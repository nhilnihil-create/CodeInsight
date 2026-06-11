#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(){
    int a,b,c,d;
    cin >> a;
    int mx = 1;
    for(int i=2; i*i<=a; i++)
    {
        int val = i;
        while(val*i<=a)
        {
            val*=i;
        }
        mx = max(mx,val);

    }
    cout << mx << endl;
}
