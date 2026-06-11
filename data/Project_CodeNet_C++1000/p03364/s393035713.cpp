//
//  main.cpp
//  Find Symmetries
//
//  Created by Dong Truong on 7/18/19.
//  Copyright © 2019 Dong Truong. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>

using namespace std;
#define gh 303

struct vt
{
    long x,y;
};

long n,d[gh][gh],a[gh][gh];

void nhap()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            char c;cin>>c;
            long o=c-'a'+1;
            a[i][j]=o;
        }
}
void sol()
{
    long kq=0;
    for (int k=0;k<n;++k)
    {
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
            {
                long o=(i+k)%n;
                if (o==0) o=n;
                d[i][j]=a[o][j];
            }
        bool kt=true;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (d[i][j]!=d[j][i]) kt=false;
        if (kt==true) kq=kq+n;
    }
    cout<<kq;
}
int main(int argc, const char * argv[]) {
    //freopen("a.inp","r",stdin);
    nhap();
    sol();
    return 0;
}
