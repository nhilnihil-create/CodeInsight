#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    if(a<=16 && b<=16 && (a+b)<=16){
        if(a==b || a==(b+1) || b==(a+1)){
            cout << "Yay!" << endl;
        }
        else{
            cout << ":(" << endl;
        }
    }
    return 0;
}
