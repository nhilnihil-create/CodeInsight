#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//for(int i = 0; i<n; i++)

int main()
{
    int n,a,b;
    cin >>n >>a >>b;
    int p1 = 0, p2 = 0, p3 = 0;
    for(int i = 0; i < n; i++){
        int p; cin>>p;
        if(p <= a) p1++;
        else if(p <= b) p2++;
        else p3++;
    }
    cout << min(p1, min(p2, p3)) <<endl;
    return 0;
}

