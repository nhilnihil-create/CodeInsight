#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,sum;
    cin >> a >> b;
    if(a<b){
        sum = b+(b-1);
    }
    else if(a>b){
        sum = a+(a-1);
    }
    else{
        sum = a+a;
    }
    cout << sum << endl;
    return 0;
}
