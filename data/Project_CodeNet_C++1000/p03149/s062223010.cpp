#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
#define PB push_back
#define MP make_pairA
#define REP(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n[4];
    REP(i,4)cin>>n[i];
    sort(n,n+4);
    if(n[0]==1&&n[1]==4&&n[2]==7&&n[3]==9){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}