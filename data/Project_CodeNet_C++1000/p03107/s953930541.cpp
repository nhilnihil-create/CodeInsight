#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >>s;
    int n = s.length();
    int a = 0;
    int b = 0;
    for(int i = 0;i< n;i++)
    {
        if(s[i] == '0')
        {
            a++;
        }
        else if(s[i] == '1')
        {
            b++;
        }
    }
    int ans = min(a,b);;
    
    cout << ans*2 << endl;
}
