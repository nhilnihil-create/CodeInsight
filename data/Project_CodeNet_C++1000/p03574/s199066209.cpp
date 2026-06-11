#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,w,i=0,j,c=0;
    char a;
    string s[100],m="a";
    cin >> h >> w;
    for(i=1;i<h+1;i++)
    {
        cin >> s[i];
        s[i]=m+s[i]+m;
    }
    s[0]=string(w+3, 'x');
    s[h+1]=string(w+3,'x');
    for(i=1;i<h+1;i++)
    {
        for(j=1;j<w+1;j++)
        {
            if(s[i].at(j)=='#')
            {
                continue;
            }
            if(s[i-1].at(j-1)=='#')
            {
                c++;
            }
            if(s[i-1].at(j)=='#')
            {
                c++;
            }
            if(s[i-1].at(j+1)=='#')
            {
                c++;
            }
            if(s[i].at(j-1)=='#')
            {
                c++;
            }
            if(s[i].at(j+1)=='#')
            {
                c++;
            }
            if(s[i+1].at(j-1)=='#')
            {
                c++;
            }
            if(s[i+1].at(j)=='#')
            {
                c++;
            }
            if(s[i+1].at(j+1)=='#')
            {
                c++;
            }
            a=c + '0';
            s[i].at(j)=a;
            c=0;
        }
    }
    for(i=1;i<h+1;i++)
    {
        cout << s[i].substr(1,w) << endl;
    }
    
    return 0;

}
