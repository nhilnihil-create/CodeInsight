#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,i=0,j,c=0,p,h[1000010],m=0,max=0;
    string s;
    cin >> s;
    p=s.size();
    for(i=1;i<p;i++)
    {
        if(i%2==1 && s[i]==s[0])
        {
            max++;
        }
        else if(i%2==0 && s[i]!=s[0])
        {
            max++;
        }
            
    }
    cout << max << endl;
    return 0;

}
