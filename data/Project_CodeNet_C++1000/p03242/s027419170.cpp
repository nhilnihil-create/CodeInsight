#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    string a;
    cin>>a;
    for(char c:a){
        if(c == '1'){
            cout<<9;
        }
        else{
            cout<<1;
        }
    }


    return 0;
}
