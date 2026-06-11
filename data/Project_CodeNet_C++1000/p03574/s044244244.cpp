#include <bits/stdc++.h>
using namespace std;
int main()
{
        int x,y;cin>>x>>y;
        char a[x][y];
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                cin>>a[i][j];
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                int c=0;
            if(a[i][j]=='.')
            {
                if(a[i-1][j]=='#' &&i!=0)
                    c++;
                if(a[i+1][j]=='#'&&i!=x-1)
                    c++;
                if(a[i][j-1]=='#'&&j!=0)
                    c++;
                if(a[i][j+1]=='#' && j!=y-1)
                    c++;
                if(a[i+1][j+1]=='#' && j!=y-1)
                    c++;
                if(a[i-1][j-1]=='#'&&j!=0&&i!=0)
                    c++;
                if(a[i+1][j-1]=='#'&&j!=0&&i!=x-1)
                    c++;
                if(a[i-1][j+1]=='#'&&i!=0&&j!=y-1)
                    c++;
            char d='0'+c;
         a[i][j]=d;
            }
        }
        }
                for(int i=0;i<x;i++){
            for(int j=0;j<y;j++)
                cout<<a[i][j];
                cout<<endl;
                }
    return 0;
   }