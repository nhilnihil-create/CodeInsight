#include <bits/stdc++.h>
int cou(int x)
{
    int count=0;
    while(x%10!=0)
    {
        x++;
        count++;
    }
    return count;
}
    
    
using namespace std;
int main(void){
    long long int i=0,j,a,b,c,d,e,a1,b1,c1,d1,e1,m;
    string s;
    cin >> a >> b >> c >> d >> e;
    a1=cou(a);
    b1=cou(b);
    c1=cou(c);
    d1=cou(d);
    e1=cou(e);
    m=max({a1,b1,c1,d1,e1});
    cout << a+b+c+d+e+a1+b1+c1+d1+e1-m << endl;
    return 0;

}
