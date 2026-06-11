#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    double r=0;
    for(int i=1;i<=a;i++)
    {

        double t = 1.0/a;
        int n =i;
        while(n<b)
        {
            n = n*2;
            t = t/2;
        }
        r +=t;
    }
    printf("%.12f",r);
}
