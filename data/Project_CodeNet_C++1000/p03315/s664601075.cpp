#include<bits/stdc++.h>
#define N 1005
using namespace std;
string s;
int ans;
int main()
{
    cin>> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '+')
            ans++;
        else
            ans--;
    }
    cout<< ans;
    return 0;
}
