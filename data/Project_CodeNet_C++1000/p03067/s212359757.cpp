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
    int a,b,c;
    cin>>a>>b>>c;
    if(b<a)swap(a,b);
    if(c>=a&&c<=b)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}