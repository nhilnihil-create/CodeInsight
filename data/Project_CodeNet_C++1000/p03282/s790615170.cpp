#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j,c=0,p,h[1000010],m=1,max=0,k;
    string s;
    cin >> s >> k;
    for(i=0;i<k;i++)
    {
        if(s[i]!='1')
        {
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << '1' << endl;
    
    return 0;

}
