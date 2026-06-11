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
    string s;
    cin>>s;
    int cnt=0;
    REP(i,s.size())if(s[i]=='2')cnt++;
    cout<<cnt<<endl;
}