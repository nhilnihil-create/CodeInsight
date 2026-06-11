#include<bits/stdc++.h>
using namespace std;

int main()
{
    //input
    int h,w,i,j;
    cin>>h>>w;
    char field[h][w];
    int num_bomb[h][w]={};
    //input and processing
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            cin>>field[i][j];
            if(field[i][j]=='#')
            {
                if(i-1>=0 && j-1>=0) num_bomb[i-1][j-1]++;
                if(i-1 >= 0) num_bomb[i-1][j]++;
                if(i-1>=0 && j+1<w) num_bomb[i-1][j+1]++;
                if(j-1 >= 0) num_bomb[i][j-1]++;
                if(j+1 < w) num_bomb[i][j+1]++;
                if(i+1<h && j-1>=0) num_bomb[i+1][j-1]++;
                if(i+1 < h) num_bomb[i+1][j]++;
                if(i+1<h && j+1<w) num_bomb[i+1][j+1]++;
            }
        }
    }
    
    //output
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(field[i][j]=='#') cout<<field[i][j];
            else cout<<num_bomb[i][j];
        }
        cout<<endl;
    }
}