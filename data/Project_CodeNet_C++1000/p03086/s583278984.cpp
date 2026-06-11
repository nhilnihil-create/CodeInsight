#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,i=0,j,c=0,p,h[1000010],m=0,max=0;
    string s;
    cin >> s;
    c=s.size();
    for(i=0;i<c;i++)
    {
        if(s.at(i)=='A'||s.at(i)=='C'||s.at(i)=='G'||s.at(i)=='T')
        {
            m++;
        }
        else
        {
            m=0;
        }
        if(max<m)
        {
            max=m;
        }
    }
    cout << max << endl;
    return 0;

}
