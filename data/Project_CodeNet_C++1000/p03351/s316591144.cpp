#include<bits/stdc++.h>

using namespace std;

int main(){

    int a,c,d,b;

    cin >> a >> b >> c >> d;

    int flag = 0;

    if(abs(a-c)<=d) cout << "Yes" << endl;

    else{

       if(abs(a-b)<=d && abs(b-c)<=d)

         cout << "Yes" << endl;

       else cout << "No" << endl;

    }

    return 0;

}