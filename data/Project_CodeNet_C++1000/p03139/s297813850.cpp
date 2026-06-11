#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int max=0;
    int min=0;
    if(a>=b) max=b;
    else max=a;
    min=n-a;
    min-=b;
    if(min>=0) min=0;
    cout << max << " " << abs(min) << endl;
}