#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<limits>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    queue<int> q;
    int j=0;
    int k=1;
    int x= sqrt(m);

    for(int i=1;i<x+1;i++){
        if(m%i==0){
            q.push(i);
            q.push(m/i);
            j+=2;
        }
    }

    for(int i=0;i<j;i++){
        if(n<=m/q.front()&&q.front()>k){
            k=q.front();
        }
        q.pop();
    }
    cout<<k<<endl;


    return 0;
}